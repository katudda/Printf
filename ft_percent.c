/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_percent.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchristi <kchristi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 12:16:54 by kchristi          #+#    #+#             */
/*   Updated: 2021/07/08 19:01:01 by kchristi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_isspec(int c)
{
	return ((c == 'c') || (c == 's') || (c == 'p') || (c == 'd') || (c == 'i')
		|| (c == 'u') || (c == 'x') || (c == 'X') || (c == '%'));
}

int	ft_isflag(int c)
{
	return ((c == '.') || (c == '*') || (c == '0') || (c == '-') || (c == ' '));
}

int	ft_handle(int c, t_flags flags, va_list args)
{
	int	count;

	count = 0;
	if (c == 'c')
		count = ft_char_handler(va_arg(args, int), flags);
	else if (c == '%')
		count += ft_flag_handler(flags);
	else if (c == 'p')
		count = ft_pointer_handler(va_arg(args, unsigned long long), flags);
	else if (c == 's')
		count = ft_string_handler(va_arg(args, char *), flags);
	else if ((c == 'i') || (c == 'd'))
		count = ft_int_handler(va_arg(args, int), flags);
	else if (c == 'x')
		count += ft_hex_handler(va_arg(args, unsigned int), 1, flags);
	else if (c == 'X')
		count += ft_hex_handler(va_arg(args, unsigned int), 0, flags);
	else if (c == 'u')
		count += ft_u_handler((unsigned int)va_arg(args, unsigned int), flags);
	return (count);
}

int	ft_flag_handler(t_flags flags)
{
	int	count;

	count = 0;
	if (flags.minus == 1)
		count += ft_put_spec("%", 1);
	count += ft_width_handler(flags.width, 1, flags.zero);
	if (flags.minus == 0)
		count += ft_put_spec("%", 1);
	return (count);
}
