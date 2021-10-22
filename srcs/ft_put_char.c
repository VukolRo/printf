/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shavok <shavok@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 18:59:16 by shavok            #+#    #+#             */
/*   Updated: 2021/10/22 18:14:15 by shavok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_char(t_struct *s, va_list vl)

{
	unsigned char	ch;

	ch = (unsigned char)va_arg(vl, int);
	s->count_printed += write(1, &ch, 1);
}
