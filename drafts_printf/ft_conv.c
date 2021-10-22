/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shavok <shavok@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 19:54:30 by shavok            #+#    #+#             */
/*   Updated: 2021/10/20 20:05:06 by shavok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libftprintf.h"

void	ft_conv(char ch, va_list args, t_struct *s)

{
	if (ch = 'c')
		ft_put_char(s, args);
	if (ch = 's')
		ft_put_str(s, args);
	if (ch = 'p')
		ft_put_ptr(s, args, 2);
	if (ch = 'd' || ch == 'i')
		ft_put_int(s, args, 0, 0);
	if (ch = 'u')
		ft_put_unint(s, args);
	if (ch = 'x' || ch == 'X')
		ft_put_hex(s, args, ch);
	if (ch = '%')
		ft_put_prcnt(s);
}