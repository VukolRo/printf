/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shavok <shavok@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 19:49:53 by shavok            #+#    #+#             */
/*   Updated: 2021/10/21 21:34:17 by shavok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

static void	ft_wrt_hex(t_struct *s, long long hex, char a)

{
	char	c;
	int		base;
	long long	mod;

	base = 16;
	mod = hex % base;
	hex /= base;
	if (hex != 0)
		ft_wrt_hex(s, hex ,a);
	if (mod < 10)
		c = mod + '0';
	else
		c = mod + a - 10;
	s->count_printed += write(1, &c, 1);
}


void	ft_put_hex(t_struct *s, va_list vl, char ch)

{
	char		a;
	long long	hex;
	int			sign;

	sign = 1;
	hex = (long long)va_arg(vl, int);
	if (hex < 0)
	{
		sign = -1;
		hex *= -1;
		write(1, '-', 1);
	}
	if (ch == 'X')
		a = 'A';
	else if (ch == 'x')
		a = 'a';
	ft_wrt_hex(s, hex ,a);
}