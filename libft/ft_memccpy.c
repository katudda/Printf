/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchristi <kchristi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 16:06:02 by kchristi          #+#    #+#             */
/*   Updated: 2021/06/04 23:26:35 by kchristi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*dsrc;
	unsigned char	*ddst;
	size_t			count;

	count = 0;
	dsrc = (unsigned char *) src;
	ddst = (unsigned char *) dst;
	while (count < n)
	{
		ddst[count] = dsrc[count];
		if (dsrc[count] == (unsigned char)c)
			return (dst + count + 1);
		count++;
	}
	return (NULL);
}
