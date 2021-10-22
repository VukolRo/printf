/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shavok <shavok@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 20:24:26 by shavok            #+#    #+#             */
/*   Updated: 2021/10/20 20:30:53 by shavok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libftprintf.h"

static void	sft_right_aligned_str(t_struct *s, char ch, char *ar, int j)

{

}

static void	sft_left_aligned_str(t_struct *s, char ch, char *ar, int j))

{
	
}
void	ft_put_str(t_struct *s, va_list args)

{
	char	*ar;
	char	ch;
	int		j;

	if (s->zero == 1)
		ch = '0';
	else
		ch = ' ';
	ar = (char *)va_arg(args, char *);
	if (ar == NULL)
		ar = "(null)";
	j = ft_strlen(ar);
	if (s->minus == 1)
		sft_right_aligned_str(s, ch, ar, j);
	else if (s->minus == 0)
		sft_left_aligned_str(s, ch, ar, j);
}