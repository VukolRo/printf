/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shavok <shavok@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 15:59:11 by shavok            #+#    #+#             */
/*   Updated: 2021/10/22 18:26:40 by shavok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "./libft/libft.h"

typedef struct s_struct
{
	char	*frmt;
	int		count_printed;
}			t_struct;

int			ft_printf(const char *frmt, ...);
int			ft_to_percent(const char *frmt, t_struct *s, va_list vl, int loc);
void		ft_spec(char ch, t_struct *s, va_list vl);

void		ft_put_char(t_struct *s, va_list vl);
void		ft_put_str(t_struct *s, va_list vl);
void		ft_put_prcnt(t_struct *s);
void		ft_put_int(t_struct *s, va_list vl);
void		ft_put_unint(t_struct *s, va_list vl);
void		ft_put_hex(t_struct *s, va_list vl, char ch);
void		ft_put_ptr(t_struct *s, va_list vl);

#endif