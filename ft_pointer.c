/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchristi <kchristi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 20:43:31 by kchristi          #+#    #+#             */
/*   Updated: 2021/07/08 11:57:37 by kchristi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_get_pointer(char *pointer, t_flags flags)
{
	int	count;

	count = 0;
	count += ft_put_spec("0x", 2);
	if (flags.dot >= 0)
	{
		count += ft_width_handler(flags.dot, ft_strlen(pointer), 1);
		count += ft_put_spec(pointer, flags.dot);
	}
	else
		count += ft_put_spec(pointer, ft_strlen(pointer));
	return (count);
}

static int	ft_verify_handler(int count, t_flags flags)
{
	if (flags.width >= 0 && flags.minus == 0)
	{
		count += ft_width_handler(flags.width - 2, 0, 0);
		count += ft_put_spec("0x", 2);
	}
	else
	{
		count += ft_put_spec("0x", 2);
		count += ft_width_handler(flags.width - 2, 0, 0);
	}
	return (count);
}

int	ft_pointer_handler(unsigned long long num, t_flags flags)
{
	int		count;
	char	*p;

	count = 0;
	if (flags.dot == 0 && !num)
		return (ft_verify_handler(count, flags));
	p = ft_utl_base(num, 16);
	p = ft_str_tolower(p);
	if ((size_t)flags.dot < ft_strlen(p))
		flags.dot = ft_strlen(p);
	if (flags.minus == 1)
		count += ft_get_pointer(p, flags);
	count += ft_width_handler(flags.width, ft_strlen(p) + 2, 0);
	if (flags.minus == 0)
		count += ft_get_pointer(p, flags);
	free(p);
	return (count);
}
