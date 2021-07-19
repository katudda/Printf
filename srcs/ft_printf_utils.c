/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchristi <kchristi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 20:11:57 by kchristi          #+#    #+#             */
/*   Updated: 2021/07/08 19:24:32 by kchristi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_spec(char *str, int precision)
{
	int	i;

	i = 0;
	while (str[i] && i < precision)
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}

static	char	*ft_base(unsigned long long num, int base, int count, char *str)
{
	while (num != 0)
	{
		if ((num % base) < 10)
			str[count - 1] = (num % base) + 48;
		else
			str[count - 1] = (num % base) + 55;
		num /= base;
		count--;
	}
	return (str);
}

char	*ft_utl_base(unsigned long long num, int base)
{
	unsigned long long	temp;
	int					count;
	char				*str;

	temp = num;
	str = 0;
	count = 0;
	if (num == 0)
		return (ft_strdup("0"));
	while (num != 0)
	{
		num /= base;
		count++;
	}
	str = malloc(count + 1);
	if (!str)
		return (0);
	str[count] = '\0';
	str = ft_base(temp, base, count, str);
	return (str);
}

char	*ft_str_tolower(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		str[i] = ft_tolower(str[i]);
		i++;
	}
	return (str);
}
