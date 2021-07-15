/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchristi <kchristi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 23:11:46 by kchristi          #+#    #+#             */
/*   Updated: 2021/06/04 23:26:35 by kchristi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t			c;

	c = 0;
	if (src == 0)
		return (0);
	if (dstsize > 0)
	{
		while (c < (dstsize - 1) && src[c] != '\0')
		{
			dst[c] = src[c];
			c++;
		}
		dst[c] = '\0';
	}
	return (ft_strlen(src));
}
