/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shavok <shavok@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 11:45:51 by shavok            #+#    #+#             */
/*   Updated: 2021/10/21 12:57:11 by shavok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libftprintf.h"

int	ft_signzerowidht(t_struct *s, char c, char sign_char, int sign)

{
	if (s->width > 0 && c == '0')
	{
		if (s->space)
		{
			s->to_print += write(1, " ", 1);
			s->space = 0;
		}
		if (sign_char != '\0')
			s->to_print += write(1, &sign_char, 1);
		sign -= sign;
	}
	return (sign);
}

void	ft_left_aligned_int(t_struct *s, int len, char *str, int sign)

{
	if (s->space)
		s->to_print += write(1, " ", 1);
	if (sign == POSITIVE)
		s->to_print += write(1, "+", 1);
	else if (sign == NEGATIVE)
		s->to_print += write(1, "-", 1);
	while (s->precision > 0)
	{
		s->to_print += write(1, "0", 1);
		s->precision--;
	}
	s->to_print += write(1, str, len);
	while (s->width > 0)
	{
		s->to_print += write(1, " ", 1);
		s->width--;
	}
	
}

void	ft_right_aligned_int(t_struct *s, int len, char *str, int sign)

{
	char	sign_char;
	char	c;

	if (s->zero && !s->valid_precision)
		c = '0';
	else
		c = ' ';
	sign_char = '\0';
	if (sign == POSITIVE)
		sign_char = '+';
	else if (sign == NEGATIVE)
		sign_char = '-';
	sign = ft_signzerowidht(s, c, sign_char, sign);
	while (s->width-- > 0)
		s->to_print += write(1, &c, 1);
	if (s->space != 0)
		s->to_print += write(1, " ", 1);
	if (sign != 0 && sign_char != '\0')
		s->to_print += write(1, &sign_char, 1);
	while (s->precision-- > 0)
		s->to_print += write(1, "0", 1);
	s->to_print += write(1, s, len);
}

void	ft_formating_int(intmax_t j, t_struct *s, int sign)

{
	int		len;
	char	*str;

	if (s->space && sign != 0)
		s->space = 0;
	str = ft_itoa_base_up(j, 10);
	len = ft_signed_nbr_len(j, 10);
	if (j == 0)
		len = 1;
	if (s->valid_precision == 1 && s->precision == 0 && j == 0)
		len = 0;
	if (s->valid_precision && s->precision > len)
		s->precision = s->precision - len;
	else
		s->precision = 0;
	if (sign != 0)
		s->width = s->width - (s->precision + len + 1 + s->space);
	else
		s->width = s->width - (s->precision + len + s->space);
	if (s->minus == 0)
		ft_right_aligned_int(s, len, str, sign);
	if (s->minus == 1)
		ft_left_aligned_int(s, len, str, sign);
		free(str);
}

void	ft_put_int(t_struct *s, va_list args, int sign, intmax_t j)

{
	if (s->len == 0)
		j = (int)va_arg(args, int);
	if (s->plus && j >= 0)
		sign = POSITIVE;
	if (j < 0)
	{
		sign = NEGATIVE;
		j = j * (-1);
	}
	ft_formating_int(j, s, sign);
}