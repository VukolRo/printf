/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shavok <shavok@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 18:36:03 by shavok            #+#    #+#             */
/*   Updated: 2021/10/20 19:00:25 by shavok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libftprintf.h"

int	ft_parse(const char *frmt, t_struct *s, va_list args, int loc)

{
	s->i = loc;
	if (!ft_strchr(TYPES, frmt[loc]))
		ft_mod(frmt, args, s);
	else if (ft_strchr(TYPES, frmt[loc]))
	{
		ft_conv(frmt[loc], args, s);
		ft_bzero(s, sizeof(t_struct));
	}
	return (s->i - 1);
}