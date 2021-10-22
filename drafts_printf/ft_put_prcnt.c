/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_prcnt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shavok <shavok@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 20:13:08 by shavok            #+#    #+#             */
/*   Updated: 2021/10/20 20:20:47 by shavok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libftprintf.h"

void	ft_put_prcnt(t_struct *s)

{
	int nmbr;

	if (s->width && s->minus == 0)
	{
		nmbr = s->width -1;
		if (s->zero != 0)
			writezero(nmbr);
		if (s->zero == 0)
			writespace(nmbr);
		write(1, "%", 1);
		s->to_print = s->to_print + nmbr;
	}
	else if (s->width && s->minus == 1)
	{
		nmbr = s->width - 1;
		write(1, "%", 1);
		writespace(nmbr);
		s->to_print = s->to_print + nmbr;
	}
	else
		write(1, "%", 1);
	s->to_print++;
}