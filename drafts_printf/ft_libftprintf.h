/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libftprintf.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shavok <shavok@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 16:09:04 by shavok            #+#    #+#             */
/*   Updated: 2021/10/21 19:47:24 by shavok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIBFTPRINTF_H
# define FT_LIBFTPRINTF_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

# define ALL_S "cspdiuxX%# +-0.*123456789"
# define TYPES "cspdiuxX%"

# define POSITIVE 1
# define NEGATIVE 2

typedef struct s_struct
{
	char	*format;
	int		to_print;
	int		i;
	int		len;
	int		minus;
	int		zero;
	int		precision;
	int		width;
	int		hash;
	int		space;
	int		plus;
	int		valid_precision;
	int		length;
}			t_struct;


int			ft_printf(const char *frmt, ...);
int			ft_find_prcnt(const char *frmt, t_struct *s, va_list args, int loc);
int			ft_parse(const char *frmt, t_struct *s, va_list args, int loc);

void		ft_mod(const char *frmt, va_list args, t_struct *s);
void		ft_conv(char ch, va_list args, t_struct *s);
void		ft_put_char(t_struct *s, va_list args);
void		ft_put_prcnt(t_struct *s);
void		ft_put_str(t_struct *s, va_list args);
void		ft_put_ptr(t_struct *s, va_list args, int p);
void		ft_put_int(t_struct *s, va_list args, int sign, intmax_t j);
void		ft_put_hex(t_struct *s, va_list args, char ch);
void		ft_put_unint(t_struct *s, va_list args);

char		*ft_itoa_base(uintmax_t val, uintmax_t base);
char		*ft_itoa_base_up(intmax_t val, intmax_t base);

int			ft_signed_nbr_len();
int			ft_unsigned_nbr_len();

#endif