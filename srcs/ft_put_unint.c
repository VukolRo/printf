/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_unint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shavok <shavok@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 19:48:02 by shavok            #+#    #+#             */
/*   Updated: 2021/10/22 18:22:38 by shavok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_itoa_un_recurs(t_struct *s, unsigned int m)

{
	char	c;
	int		mod;

	mod = m % 10;
	m /= 10;
	if (m != 0)
		ft_itoa_un_recurs(s, m);
	c = mod + 48;
	s->count_printed += write(1, &c, 1);
}

void	ft_put_unint(t_struct *s, va_list vl)

{
	unsigned long	m;

	m = (unsigned int)va_arg(vl, unsigned int);
	ft_itoa_un_recurs(s, m);
}
