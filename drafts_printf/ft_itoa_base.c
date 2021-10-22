/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shavok <shavok@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 20:35:52 by shavok            #+#    #+#             */
/*   Updated: 2021/10/20 20:43:38 by shavok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libftprintf.h"

char		*ft_itoa_base(uintmax_t val, uintmax_t base)

{
	char				*ch;
	unsigned long long	n;
	int					j;

	j = 1;
	n = val;
	while ((n /= base) >= 1)
		j++;
	ch = (char *)ft_calloc(j + 1, sizeof(char));
	n = val;
	while (j-- > 0)
	{
		ch[j] = (n % base < 10) ? n % base + '0' : n % base + 'a' - 10;
		n /= base;
	}
	return (ch);
}