/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchristi <kchristi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 20:56:47 by kchristi          #+#    #+#             */
/*   Updated: 2021/06/04 23:26:35 by kchristi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_element;

	if (lst == 0)
		return (NULL);
	new_element = ft_lstnew((*f)(lst->content));
	if (new_element == NULL)
	{
		free(new_element);
		return (NULL);
	}
	new_lst = new_element;
	lst = lst->next;
	while (lst)
	{
		new_element->next = ft_lstnew((*f)(lst->content));
		if (new_element == NULL)
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		new_element = new_element->next;
		lst = lst->next;
	}
	return (new_lst);
}
