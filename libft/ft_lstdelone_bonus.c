/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobaya <hakobaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 23:59:01 by hakobaya          #+#    #+#             */
/*   Updated: 2023/06/10 01:45:51 by hakobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst == NULL || del == NULL)
		return ;
	(*del)(lst->content);
	free(lst);
}

//#include <stdio.h>

//int	main(void)
//{
//	t_list	*new;
//	void	*content;

//	content = ft_strdup("sdfghj");
//	new = ft_lstnew(content);
//	printf("%s\n", new->content);
//	ft_lstdelone(new, free);
//	printf("%s\n", new->content);
//	//free(new->next);
//}
