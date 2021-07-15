/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchristi <kchristi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 18:32:21 by kchristi          #+#    #+#             */
/*   Updated: 2021/07/04 13:41:03 by kchristi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_get_string(char *str, t_flags flags)
{
	int	count;

	count = 0;
	if (flags.dot >= 0)
	{
		count += ft_width_handler(flags.dot, ft_strlen(str), 0);
		count += ft_put_spec(str, flags.dot);
	}
	else
		count += ft_put_spec(str, ft_strlen(str));
	return (count);
}

int	ft_string_handler(char *str, t_flags flags)
{
	int	count;

	count = 0;
	if (!str)
		str = "(null)";
	if (flags.dot >= 0 && (size_t)flags.dot > ft_strlen(str))
		flags.dot = ft_strlen(str);
	if (flags.minus == 1)
		count += ft_get_string(str, flags);
	if (flags.dot >= 0)
		count += ft_width_handler(flags.width, flags.dot, 0);
	else
		count += ft_width_handler(flags.width, ft_strlen(str), flags.zero);
	if (flags.minus == 0)
		count += ft_get_string(str, flags);
	return (count);
}

int	ft_char_handler(char c, t_flags flags)
{
	int	count;

	count = 0;
	if (flags.minus == 1)
		ft_putchar(c);
	count = ft_width_handler(flags.width, 1, 0);
	if (flags.minus == 0)
		ft_putchar(c);
	return (count + 1);
}
