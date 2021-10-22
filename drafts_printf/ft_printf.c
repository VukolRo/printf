/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shavok <shavok@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 16:07:01 by shavok            #+#    #+#             */
/*   Updated: 2021/10/20 17:22:39 by shavok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libftprintf.h"

int	ft_printf(const char *frmt, ...)

{
	va_list		args;
	t_struct	*strct;
	int			frmt_len;
	int			ret;

	if (!(strct = (t_struct *)ft_calloc(1, sizeof(t_struct))))
		return (0);
	frmt_len = ft_strlen(frmt);
	strct->format = (char *)frmt;
	va_start(args, frmt);
	if (!frmt)
	{
		write(1, "", 0);
		return (0);
	}
	else if (frmt_len == 1 && frmt[0] == '%')
		return (0);
	else
		ret = ft_find_prcnt(frmt, strct, args, 0);
	va_end(args);
	free(strct);
	return (ret);
}