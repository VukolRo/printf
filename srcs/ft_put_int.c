/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shavok <shavok@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 19:17:06 by shavok            #+#    #+#             */
/*   Updated: 2021/10/21 19:49:33 by shavok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

void	ft_put_int(t_struct *s, va_list vl)

{
	char	*nmbr;

	nmbr = ft_itoa(va_arg(vl, int));
	while (*nmbr)
	{
		write(1, &nmbr, 1);
		nmbr++;
		s->count_printed++;
	}
}