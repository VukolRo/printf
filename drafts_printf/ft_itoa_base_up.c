/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_up.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shavok <shavok@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 20:47:30 by shavok            #+#    #+#             */
/*   Updated: 2021/10/21 21:10:49 by shavok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libftprintf.h"

char	*ft_itoa_base_up(intmax_t val, intmax_t base)

{
	char		*ch;
	long long	n;
	int			j;
	int			sign;

	n = (val < 0) ? -val : val;
	sign = (val < 0 && base == 10) ? -1 : 0;
	j = (sign == -1) ? 2 : 1;
	while ((n /= base) >= 1)
		j++;
	ch = (char *)ft_calloc(j + 1, sizeof(char));
	n = (val < 0) ? -val : val;
	while (j-- + sign)
	{
		if (n % base < 10)
			ch[j] = n % base + '0';
		else
			ch[j] =  n % base + 'A' - 10;
		n /= base;
	}
	(j == 0) ? ch[j] = '-' : 0;
	return (ch);
}