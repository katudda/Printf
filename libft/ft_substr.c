/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchristi <kchristi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 17:45:16 by kchristi          #+#    #+#             */
/*   Updated: 2021/06/04 23:26:34 by kchristi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	c;
	size_t	slen;

	c = 0;
	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	ptr = malloc((len + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	while (c < len && (start + c) < slen)
	{
		ptr[c] = s[c + start];
		c++;
	}
	ptr[c] = '\0';
	return (ptr);
}
