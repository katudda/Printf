/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchristi <kchristi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 22:41:36 by kchristi          #+#    #+#             */
/*   Updated: 2021/06/04 23:26:35 by kchristi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*ds1;
	unsigned char	*ds2;

	ds1 = (unsigned char *) s1;
	ds2 = (unsigned char *) s2;
	while (n > 0)
	{
		if (*ds1 != *ds2)
			return (*ds1 - *ds2);
		n--;
		ds1++;
		ds2++;
	}
	return (0);
}
