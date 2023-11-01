/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobaya <hakobaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 00:24:01 by hakobaya          #+#    #+#             */
/*   Updated: 2023/06/09 05:10:47 by hakobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*nd;

	nd = (t_list *)malloc(sizeof(t_list));
	if (!nd)
		return (NULL);
	nd->content = content;
	nd->next = NULL;
	return (nd);
}

//int	main(void)
//{
//	t_list *lst = NULL;

//	/* ptr to char */
//	char *str = "hello world";
//	lst = ft_lstnew(str);

//	int val = 100;
//	lst = ft_lstnew(&val);
//}