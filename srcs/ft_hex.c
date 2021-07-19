/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchristi <kchristi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 20:45:30 by kchristi          #+#    #+#             */
/*   Updated: 2021/07/04 13:39:46 by kchristi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_get_hex(char *hex, t_flags flags)
{
	int	count;

	count = 0;
	if (flags.dot >= 0)
	{
		count += ft_width_handler(flags.dot - 1, ft_strlen(hex) - 1, 1);
	}
	count += ft_put_spec(hex, ft_strlen(hex));
	return (count);
}

static int	ft_put_hex(char *hex, t_flags flags)
{
	int	count;

	count = 0;
	if (flags.minus == 1)
		count += ft_get_hex(hex, flags);
	if (flags.dot >= 0 && (size_t)flags.dot < ft_strlen(hex))
		flags.dot = ft_strlen(hex);
	if (flags.dot >= 0)
	{
		flags.width -= flags.dot;
		count += ft_width_handler(flags.width, 0, 0);
	}
	else
	{
		count += ft_width_handler(flags.width, ft_strlen(hex), flags.zero);
	}
	if (flags.minus == 0)
		count += ft_get_hex(hex, flags);
	return (count);
}

int	ft_hex_handler(unsigned int number, int lowercase, t_flags flags)
{
	char	*hex;
	int		count;

	number = (unsigned int)(4294967295 + 1 + number);
	count = 0;
	if (flags.dot == 0 && number == 0)
	{
		count += ft_width_handler(flags.width, 0, 0);
		return (count);
	}
	hex = ft_utl_base((unsigned long long)number, 16);
	if (lowercase == 1)
		hex = ft_str_tolower(hex);
	count += ft_put_hex(hex, flags);
	free(hex);
	return (count);
}
