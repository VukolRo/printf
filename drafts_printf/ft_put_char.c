/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shavok <shavok@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 20:05:54 by shavok            #+#    #+#             */
/*   Updated: 2021/10/20 20:19:29 by shavok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libftprintf.h"

void	ft_put_char(t_struct *s, va_list args)

{
	int				nmbr;
	unsigned char	ch;

	ch = (unsigned char)va_arg(args, int);
	if (s->width && s->minus == 0)
	{
		nmbr = s->width -1;
		if (s->zero != 0)
			writezero(nmbr);
		if (s->zero == 0)
			writespace(nmbr);
		write(1, &ch, 1);
		s->to_print = s->to_print + nmbr;
	}
	else if (s->width && s->minus == 1)
	{
		nmbr = s->width - 1;
		write(1, &ch, 1);
		writespace(nmbr);
		s->to_print = s->to_print + nmbr;
	}
	else
		write(1, &ch, 1);
	s->to_print++;
}