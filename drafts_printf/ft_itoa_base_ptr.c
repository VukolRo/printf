/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_ptr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shavok <shavok@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 20:08:45 by shavok            #+#    #+#             */
/*   Updated: 2021/10/21 20:14:08 by shavok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

char		*ft_itoa_base_ptr(uintmax_t val, uintmax_t base)

{
	char				*ch;
	unsigned long long	n;
	int					j;

	j = 1;
	n = val;
	while ((n /= base) >= 1)
		j++;
	j += 2;
	ch = (char *)ft_calloc(j + 1, sizeof(char));
	n = val;
	ch[0] = '0';
	ch[1] = 'x';
	while (j-- > 1)
	{
		if (n % base < 10)
			ch[j] = n % base + '0';
		else
			ch[j] = n % base + 'a' - 10;
		n /= base;
	}
	return (ch);
}