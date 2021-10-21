/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shavok <shavok@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 17:46:19 by shavok            #+#    #+#             */
/*   Updated: 2021/10/21 21:43:01 by shavok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

int		ft_printf(const char *frmt, ...)

{
	va_list		vl;
	t_struct	*strct;
	int			len;
	int			ret;

	//ret = 0;
	if (!(strct = (t_struct *)ft_calloc(1, sizeof(t_struct))))
		return (0);
	len = ft_strlen(frmt);
	strct->frmt = (char *)frmt;
	va_start(vl, frmt);
	if (!frmt)
	{
		write(1, "", 0);
		return (0);
	}
	else if (len == 1 && frmt[0] == '%')
		return (0);
	else
		ret = ft_to_percent(strct, vl, 0);
	va_end(vl);
	free(vl);
	free(strct); // check is it right?
	return (ret);
}