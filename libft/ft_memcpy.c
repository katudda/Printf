/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchristi <kchristi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 15:51:31 by kchristi          #+#    #+#             */
/*   Updated: 2021/07/08 18:23:12 by kchristi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*dsrc;
	char	*ddst;
	size_t	c;

	c = 0;
	dsrc = (char *) src;
	ddst = (char *) dst;
	if (!dsrc && !ddst)
		return (NULL);
	while (c < n)
	{
		ddst[c] = dsrc[c];
		c++;
	}
	return (dst);
}
