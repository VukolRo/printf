/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_to_percent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shavok <shavok@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 18:18:52 by shavok            #+#    #+#             */
/*   Updated: 2021/10/21 18:55:05 by shavok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

int	ft_to_percent(t_struct *s, va_list vl, int loc)

{
	while (s->frmt[loc] != '\0')
	{
		if (s->frmt[loc] != '%' && s->frmt[loc])
			s->count_printed += write(1, &s->frmt[loc], 1);
		else if (s->frmt[loc] == '%')
		{
			if (!ft_strchr("cspdiuxX%", s->frmt[loc + 1]))
				break ;
			while (ft_strchr("cspdiuxX%", s->frmt[loc + 1]))
			{
				loc++;
				ft_spec(s, vl, s->frmt[loc]);
			}
			continue;
		}
		loc++;
	}
return (s->count_printed);
}
