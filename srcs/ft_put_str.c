/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shavok <shavok@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 19:03:54 by shavok            #+#    #+#             */
/*   Updated: 2021/10/22 18:21:51 by shavok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_str(t_struct *s, va_list vl)

{
	char	*str;

	str = (char *)va_arg(vl, char *);
	if (str == NULL)
		str = "(null)";
	while (*str)
	{
		write(1, str, 1);
		str++;
		s->count_printed++;
	}
}
