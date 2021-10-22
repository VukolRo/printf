/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shavok <shavok@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 19:16:49 by shavok            #+#    #+#             */
/*   Updated: 2021/10/20 14:40:48 by shavok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include "libftprintf.h"

int ft_printf(const char *prm, ...)

{
	va_list vl;
	char	*n;
	//char	*ptr;

	//ptr = NULL;
	n = "\n";
	va_start(vl, prm);
	//*ptr = *prm;
	//printf("%s\n", prm);
	while (*prm)
	{
		if (*prm == ' ')
			ft_putchar_fd('A', 1);
		if (*prm == '%' && *(prm + 1) == '%')
		{
			if (*++prm == '%')
			{
				ft_putchar_fd(va_arg(vl, int), 1);
			//	printf("%%\n", va_arg(vl, int));	//print a percent sign.
			}
		}
		else
		{
			prm++;
			if (*prm == 'c')
				ft_putchar_fd(va_arg(vl, int), 1);
				//printf("%c\n", va_arg(vl, int));	//putchar
			else if (*prm == 's')
				ft_putstr_fd(va_arg(vl, char *), 1);
				//printf("%s\n", va_arg(vl, char *));	//putstr
			// else if (*prm == 'p')
			// 	printf("%p\n", va_arg(vl, int)); 	//The void * pointer argument is printed in hexadecimal
			else if (*prm == 'd')	
				ft_putnbr_fd(va_arg(vl, int), 1);
				//printf("%d\n", va_arg(vl, int));	//putint
			else if (*prm == 'i')
				ft_putnbr_fd(va_arg(vl, int), 1);	
				//printf("%i\n", va_arg(vl, int));	//putint
			// else if (*prm == 'u')
			// 	printf("%c\n", va_arg(vl, int));	//print an unsigned decimal (base 10) number.
			// else if (*prm == 'x')
			// 	printf("%s\n", va_arg(vl, char *));	//print a number in hexadecimal (base 16), with lowercase.
			// else if (*prm == 'X')
			// 	printf("%f\n", va_arg(vl, double));	//print a number in hexadecimal (base 16), with uppercase.
		}
		write(1, n, 1);
		prm++;
	}
	va_end(vl);
	return (0);
}

int main()
{
	
	//printf(" %d %d %d %d %d %d %d", 2147483647, -2147483648, +9223372036854775807, −9223372036854775808, +18446744073709551615, 0, -42);
	//printf("%d\n", "qwer");
	ft_printf("%d%i%s%c%%%p", 21, 42, "oi, lol", 'R', '%');
	return (0);
}