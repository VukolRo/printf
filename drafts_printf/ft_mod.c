/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mod.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shavok <shavok@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 19:03:00 by shavok            #+#    #+#             */
/*   Updated: 2021/10/21 16:12:15 by shavok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libftprintf.h"

static void	sft_flags(const char *frmt, t_struct *s)

{
	while (ft_strchr("-0# +", frmt[s->i]))
	{
		if (frmt[s->i] == '-')
			s->minus = 1;
		if (frmt[s->i] == '0')
			s->zero = 1;
		if (frmt[s->i] == '#')
			s->hash = 1;
		if (frmt[s->i] == ' ')
			s->space = 1;
		if (frmt[s->i] == '+')
			s->plus = 1;
		s->i++;
	}
	if (s->plus == 1)
		s->space == 0;
}

static void	sft_width(const char *frmt, t_struct *s, va_list args)

{
	if (frmt[s->i] == '*')
	{
		s->width = va_arg(args, int);
		if (s->width < 0)
		{
			s->minus = 1;
			s->width = -(s->width);
		}
		s->i++;
	}
	if (frmt[s->i] >= '0' && frmt[s->i] <= '9')
		s->width = ft_atoi(&frmt[s->i]);
	while (frmt[s->i] >= '0' && frmt[s->i] <= '9')
		s->i++; 
}

static void	sft_precision(const char *frmt, t_struct *s, va_list args, int p)

{
	if (frmt[s->i] == '.')
	{
		s->i++;
		s->valid_precision = 1;
		if (frmt[s->i] >= '0' && frmt[s->i] <= '9')
			s->precision = ft_atoi(&frmt[s->i]);
		while (frmt[s->i] >= '0' && frmt[s->i] <= '9')
			s->i++;
		if (frmt[s->i] == '*')
		{
			p = va_arg(args, int);
			if (p >= 0)
				s->precision = p;
			else if (p < 0)
				s->valid_precision = 0;
			s->i++;			
		}
	}
}

void	ft_mod(const char *frmt, va_list args, t_struct *s)

{
	sft_flags(frmt, s);
	sft_width(frmt, s, args);
	sft_precision(frmt, s, args, 0);
}