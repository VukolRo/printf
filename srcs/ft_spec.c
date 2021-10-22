/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shavok <shavok@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 18:39:37 by shavok            #+#    #+#             */
/*   Updated: 2021/10/22 18:13:25 by shavok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_spec(char ch, t_struct *s, va_list vl)

{
	if (ch == 'c')
		ft_put_char(s, vl);
	if (ch == 's')
		ft_put_str(s, vl);
	if (ch == '%')
		ft_put_prcnt(s);
	if (ch == 'd' || ch == 'i')
		ft_put_int(s, vl);
	if (ch == 'u')
		ft_put_unint(s, vl);
	if (ch == 'x' || ch == 'X')
		ft_put_hex(s, vl, ch);
	if (ch == 'p')
		ft_put_ptr(s, vl);
}
