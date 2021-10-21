/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shavok <shavok@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 18:59:16 by shavok            #+#    #+#             */
/*   Updated: 2021/10/21 19:03:35 by shavok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

void		ft_put_char(t_struct *s, va_list vl)

{
	unsigned char ch;

	ch = (unsigned char)va_arg(vl, int);
	write(1, &ch, 1);
	s->count_printed++;
}