/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchristi <kchristi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 15:53:52 by kchristi          #+#    #+#             */
/*   Updated: 2021/06/04 23:26:35 by kchristi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str1, const char *str2, size_t len)
{
	size_t	c1;
	size_t	c2;

	if (*str2 == '\0')
		return ((char *)str1);
	c1 = 0;
	while (str1[c1] && c1 < len)
	{
		c2 = 0;
		while (str1[c2 + c1] == str2[c2] && (c1 + c2 < len))
		{
			if (str2[c2 + 1] == '\0')
				return ((char *)str1 + c1);
			c2++;
		}
		c1++;
	}
	return (NULL);
}
