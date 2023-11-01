/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobaya <hakobaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 23:22:35 by hakobaya          #+#    #+#             */
/*   Updated: 2023/06/08 05:57:24 by hakobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	char	*target;
	int		i;

	if (s == NULL)
		return ;
	i = 0;
	target = (char *)s;
	while (target[i] != '\0')
	{
		f(i, &s[i]);
		i++;
	}
}
