/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_ptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shavok <shavok@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 21:36:05 by shavok            #+#    #+#             */
/*   Updated: 2021/10/21 21:41:36 by shavok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

static void	ft_wrt_ptr(t_struct *s, unsigned long long ptr)

{
	char c;
	int base;
	unsigned long long mod;

	base = 16;
	mod = ptr % base;
	ptr /= base;
	if (ptr != 0)
		ft_wrt_ptr(s, ptr);
	if (mod < 10)
		c = mod + '0';
	else
		c = mod + 'a' - 10;
	s->count_printed += write(1, &c, 1);
}

void	ft_put_hex(t_struct *s, va_list vl)

{
	unsigned long long ptr;

	ptr = (unsigned long long)va_arg(vl, int);
	write(1, '0x', 2);
	ft_wrt_ptr(s, ptr);
}