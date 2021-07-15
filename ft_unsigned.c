/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchristi <kchristi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 20:49:19 by kchristi          #+#    #+#             */
/*   Updated: 2021/07/04 13:31:57 by kchristi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_get_unsigned(char *u_num, t_flags flags)
{
	int	count;

	count = 0;
	if (flags.dot >= 0)
		count += ft_width_handler(flags.dot - 1, ft_strlen(u_num) - 1, 1);
	count += ft_put_spec(u_num, ft_strlen(u_num));
	return (count);
}

static int	ft_put_unsigned(char *u_num, t_flags flags)
{
	int	count;

	count = 0;
	if (flags.minus == 1)
		count += ft_get_unsigned(u_num, flags);
	if (flags.dot >= 0 && (size_t)flags.dot < ft_strlen(u_num))
		flags.dot = ft_strlen(u_num);
	if (flags.dot >= 0)
	{
		flags.width -= flags.dot;
		count += ft_width_handler(flags.width, 0, 0);
	}
	else
		count += ft_width_handler(flags.width, ft_strlen(u_num), flags.zero);
	if (flags.minus == 0)
		count += ft_get_unsigned(u_num, flags);
	return (count);
}

int	ft_u_handler(unsigned int nbr, t_flags flags)
{
	int		count;
	char	*u_num;

	count = 0;
	nbr = (unsigned int)(4294967295 + 1 + nbr);
	if (flags.dot == 0 && nbr == 0)
	{
		count += ft_width_handler(flags.width, 0, 0);
		return (count);
	}
	u_num = ft_uitoa(nbr);
	count = ft_put_unsigned(u_num, flags);
	free(u_num);
	return (count);
}
