/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_prcnt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shavok <shavok@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 18:04:07 by shavok            #+#    #+#             */
/*   Updated: 2021/10/20 18:35:40 by shavok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libftprintf.h"

int	ft_find_prcnt(const char *frmt, t_struct *s, va_list args, int loc)

{
	while (frmt[loc] != '\0')
	{
		if (frmt[loc] != '%' && frmt[loc])
			s->to_print	+= write(1, &frmt[loc], 1);
		else if (frmt[loc] == '%')
		{
			if (!ft_strchr(ALL_S, frmt[loc + 1]))
				break ;
			while (ft_strchr(ALL_S, frmt[loc + 1]))
			{
				loc++;
				if (ft_strchr(TYPES, frmt[loc]))
				{
					loc = ft_parse(frmt, s, args, loc) + 2;
					break ;
				}
				else
					loc = ft_parse(frmt, s, args, loc); 
			}
			continue;
		}
		loc++;
	}
	return (s->to_print);
}