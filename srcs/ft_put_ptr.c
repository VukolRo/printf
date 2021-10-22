/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_ptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shavok <shavok@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 21:36:05 by shavok            #+#    #+#             */
/*   Updated: 2021/10/22 18:21:05 by shavok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_wrt_ptr(t_struct *s, unsigned long ptr)

{
	char			c;
	unsigned long	mod;

	mod = ptr % 16;
	ptr = ptr / 16;
	if (ptr != 0)
		ft_wrt_ptr(s, ptr);
	if (mod < 10)
		c = mod + '0';
	else
		c = (mod - 10) + 'a';
	s->count_printed += write(1, &c, 1);
}

void	ft_put_ptr(t_struct *s, va_list vl)

{
	unsigned long	ptr;

	ptr = (unsigned long)va_arg(vl, void *);
	s->count_printed += write(1, "0x", 2);
	ft_wrt_ptr(s, ptr);
}
