/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_to_percent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shavok <shavok@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 18:18:52 by shavok            #+#    #+#             */
/*   Updated: 2021/10/22 18:11:02 by shavok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_to_percent(const char *frmt, t_struct *s, va_list vl, int loc)

{
	while (frmt[loc] != '\0')
	{
		if (frmt[loc] != '%' && frmt[loc])
			s->count_printed += write(1, &frmt[loc], 1);
		else if (s->frmt[loc] == '%')
		{
			if (!ft_strchr("cspdiuxX%", frmt[loc + 1]))
				break ;
			else if (ft_strchr("cspdiuxX%", frmt[loc + 1]))
				ft_spec(frmt[++loc], s, vl);
		}
		loc++;
	}
	return (s->count_printed);
}
