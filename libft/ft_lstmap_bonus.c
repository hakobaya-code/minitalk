/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobaya <hakobaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 02:51:32 by hakobaya          #+#    #+#             */
/*   Updated: 2023/06/10 06:34:15 by hakobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*copy;

	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	new = ft_lstnew((*f)(lst->content));
	if (!new)
		return (NULL);
	copy = new;
	lst = lst->next;
	new = new->next;
	while (lst != NULL)
	{
		new = ft_lstnew((*f)(lst->content));
		if (!new)
		{
			ft_lstclear(&lst, del);
			return (NULL);
		}
		ft_lstadd_back(&copy, new);
		lst = lst->next;
	}
	return (copy);
}

//void	f(void *content)
//{
//	char	*content2;
//	size_t	i;

//	i = 0;
//	content2 = (char *)content;
//	while (content2[i] != '\0')
//	{
//		content2[i] -= 32;
//		i++;
//	}
//}

//#include <stdio.h>

//int	main(void)
//{
//	size_t	i;
//	t_list	*list;
//	void	*content;

//	i = 0;
//	while (i < 10)
//	{
//		i = i + '0';
//		content = ft_strdup((char *)i);
//		list = ft_lstnew(content);
//		list = list->next;
//		i = i - '0';
//		i++;
//	}
//	ft_lstmap(list, *f, free);
//}
