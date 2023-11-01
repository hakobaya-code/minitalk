/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobaya <hakobaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 17:10:16 by hakobaya          #+#    #+#             */
/*   Updated: 2023/06/03 23:28:57 by hakobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*get;
	size_t	i;
	size_t	sum;

	i = 0;
	sum = count * size;
	if (size != 0 && count >= SIZE_T_MAX / size)
		return (NULL);
	get = (char *)malloc(sizeof(char) * sum);
	if (!get)
		return (NULL);
	while (sum > 0)
	{
		get[i] = 0;
		i++;
		sum--;
	}
	return (get);
}
