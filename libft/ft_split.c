/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchristi <kchristi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 17:50:33 by kchristi          #+#    #+#             */
/*   Updated: 2021/06/04 23:26:34 by kchristi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_words(const char *s, char c)
{
	int	count;

	if (*s == c || !(*s))
		count = 0;
	else
		count = 1;
	while (*s)
	{
		if (*s == c && !(*(s + 1) == c || *(s + 1) == '\0'))
			count++;
		s++;
	}
	return (count);
}

static char	**ft_lstwords(const char *str, char sep, char **warray, int cwords)
{
	char	*temp;
	int		registred_words;
	int		len;

	registred_words = 0;
	while (cwords != 0 && registred_words < cwords)
	{
		temp = ft_strchr(str, sep);
		if (!temp)
			temp = ft_strchr(str, '\0');
		len = temp - str;
		if (len > 0)
		{
			warray[registred_words] = malloc(sizeof(char) * (len + 1));
			if (!warray[registred_words])
				return (NULL);
			ft_strlcpy(warray[registred_words], str, len + 1);
			registred_words++;
		}
		if (registred_words != cwords)
			str = (char const *)temp + 1;
	}
	warray[registred_words] = NULL;
	return (warray);
}

char	**ft_split(char const *s, char c)
{
	char	**lst_words;
	int		n_words;

	if (!s)
		return (NULL);
	n_words = ft_words(s, c);
	lst_words = malloc(sizeof(char *) * (n_words + 1));
	if (!lst_words)
		return (NULL);
	return (ft_lstwords(s, c, lst_words, n_words));
}
