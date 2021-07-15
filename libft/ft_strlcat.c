/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchristi <kchristi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 13:26:28 by kchristi          #+#    #+#             */
/*   Updated: 2021/06/04 23:26:34 by kchristi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t			c1;
	size_t			c2;

	c1 = 0;
	c2 = 0;
	while (dst[c1] && c1 < dstsize)
	{
		c1++;
	}
	while (src[c2] && (c1 + c2 + 1) < dstsize)
	{
		dst[c1 + c2] = src[c2];
		c2++;
	}
	if (c1 < dstsize)
		dst[c1 + c2] = '\0';
	return (c1 + ft_strlen(src));
}
