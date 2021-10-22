/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_un.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shavok <shavok@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 12:24:42 by shavok            #+#    #+#             */
/*   Updated: 2021/10/21 19:48:19 by shavok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

static int	count_rank(long long int m)

{
	int			count;

	count = 1;
	while (m >= 10)
	{
		count++;
		m /= 10;
	}
	return (count);
}

char	*ft_itoa_un(unsigned int n)

{
	char			*ret;
	int				count;

	ret = NULL;
	count = count_rank(n);
	if (n < 0)
		count += 1;
	ret = (char *)ft_calloc((count + 1), sizeof(char));
	if (ret)
	{
		while (count - 1 >= 0)
		{
			ret[count - 1] = n % 10 + 48;
			count--;
			n /= 10;
		}
	}
	return (ret);
}
