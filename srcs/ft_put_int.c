/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shavok <shavok@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 19:17:06 by shavok            #+#    #+#             */
/*   Updated: 2021/10/22 18:16:50 by shavok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_itoa_recurs(t_struct *s, long m)

{
	char	c;
	long	mod;

	mod = m % 10;
	m /= 10;
	if (m != 0)
		ft_itoa_recurs(s, m);
	c = mod + 48;
	s->count_printed += write(1, &c, 1);
}

void	ft_put_int(t_struct *s, va_list vl)

{
	long	m;

	m = (long)va_arg(vl, int);
	if (m < 0)
	{
		m *= -1;
		s->count_printed += write(1, "-", 1);
	}
	ft_itoa_recurs(s, m);
}
