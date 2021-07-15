/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchristi <kchristi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 18:17:34 by kchristi          #+#    #+#             */
/*   Updated: 2021/07/08 19:24:52 by kchristi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_flags
{
	int		dot;
	int		minus;
	int		star;
	int		type;
	int		width;
	int		zero;
}				t_flags;

char	*ft_str_tolower(char *str);
char	*ft_utl_base(unsigned long long num, int base);
int		ft_char_handler(char c, t_flags flags);
int		ft_dot(const char *str, int start, t_flags *flags, va_list args);
int		ft_flag_handler(t_flags flags);
int		ft_handle(int c, t_flags flags, va_list args);
int		ft_hex_handler(unsigned int number, int lowercase, t_flags flags);
int		ft_int_handler(int i, t_flags flags);
int		ft_isflag(int c);
int		ft_isspec(int c);
int		ft_isspec(int c);
int		ft_pointer_handler(unsigned long long num, t_flags flags);
int		ft_printf(const char *format, ...);
int		ft_put_spec(char *str, int precision);
int		ft_string_handler(char *str, t_flags flags);
int		ft_u_handler(unsigned int nbr, t_flags flags);
int		ft_width_handler(int width, int minus, int zero);
t_flags	ft_digit(char c, t_flags flags);
t_flags	ft_minus(t_flags flags);
t_flags	ft_width(va_list args, t_flags flags);

#endif