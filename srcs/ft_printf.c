/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchristi <kchristi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 21:52:33 by kchristi          #+#    #+#             */
/*   Updated: 2021/07/08 19:08:33 by kchristi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_flags	ft_set_flags(void)
{
	t_flags	flags;

	flags.width = 0;
	flags.star = 0;
	flags.type = 0;
	flags.minus = 0;
	flags.zero = 0;
	flags.dot = -1;
	return (flags);
}

static int	ft_options(const char *str, int c, t_flags *flags, va_list args)
{
	while (str[c])
	{
		if (!ft_isspec(str[c]) && !ft_isflag(str[c]) && !ft_isdigit(str[c]))
			break ;
		if (str[c] == '0' && flags->width == 0 && flags->minus == 0)
			flags->zero = 1;
		if (str[c] == '*')
			*flags = ft_width(args, *flags);
		if (str[c] == '.')
			c = ft_dot(str, c, flags, args);
		if (str[c] == '-')
			*flags = ft_minus(*flags);
		if (ft_isdigit(str[c]))
			*flags = ft_digit(str[c], *flags);
		if (ft_isspec(str[c]))
		{
			flags->type = str[c];
			break ;
		}
		c++;
	}
	return (c);
}

static int	ft_find_percent(const char *str, va_list args)
{
	int		i;
	int		count;
	t_flags	flags;

	i = 0;
	count = 0;
	while (!0)
	{
		flags = ft_set_flags();
		if (!str[i])
			break ;
		else if (str[i] != '%')
			count += ft_putchar(str[i]);
		else if (str[i] == '%' && str[i + 1])
		{
			i = ft_options(str, ++i, &flags, args);
			if (ft_isspec(str[i]))
				count += ft_handle((char)flags.type, flags, args);
			else if (str[i])
				count += ft_putchar(str[i]);
		}
		i++;
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list		args;
	const char	*str;
	int			count;

	count = 0;
	str = ft_strdup(format);
	if (!str)
		return (0);
	va_start(args, format);
	count += ft_find_percent(str, args);
	va_end(args);
	free((char *)str);
	return (count);
}
