/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchristi <kchristi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 18:53:21 by kchristi          #+#    #+#             */
/*   Updated: 2021/06/04 23:26:34 by kchristi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_comp(char const *set, char c)
{
	while (*set)
	{
		if (*set++ == c)
			return (1);
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char const	*ptr;
	size_t		set_size;
	size_t		out_size;

	if (!s1 || !set)
		return (NULL);
	ptr = s1;
	set_size = 0;
	while (ft_comp(set, *ptr) && *ptr++)
		set_size++;
	out_size = ft_strlen(s1);
	if (set_size == out_size)
		return (ft_substr(s1, set_size, 0));
	ptr = &s1[out_size - 1];
	while (ft_comp(set, *ptr--) && out_size)
	{
		out_size--;
	}
	return (ft_substr(s1, set_size, out_size - set_size));
}
