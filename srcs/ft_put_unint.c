/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_unint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shavok <shavok@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 19:48:02 by shavok            #+#    #+#             */
/*   Updated: 2021/10/21 19:49:24 by shavok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

void	ft_put_unint(t_struct *s, va_list vl)

{
	char	*nmbr;

	nmbr = ft_itoa_un(va_arg(vl, int));
	while (*nmbr)
	{
		write(1, &nmbr, 1);
		nmbr++;
		s->count_printed++;
	}
}