/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobaya <hakobaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 02:35:03 by hakobaya          #+#    #+#             */
/*   Updated: 2023/06/10 03:52:08 by hakobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (lst == NULL || f == NULL)
		return ;
	while (lst != NULL)
	{
		(*f)(lst->content);
		lst = lst->next;
	}
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
//	t_list	*new;
//	void	*content;

//	content = ft_strdup("aaa");
//	new = ft_lstnew(content);
//	ft_lstiter(new, f);
//	printf("%s\n", (char *)(new->content));
//	//free(new->next);
//}
