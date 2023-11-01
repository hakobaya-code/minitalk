/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobaya <hakobaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 14:52:14 by hakobaya          #+#    #+#             */
/*   Updated: 2023/06/01 03:25:00 by hakobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*search;
	int				i;

	search = (unsigned char *)s;
	i = 0;
	if (c > 127)
		c %= 128;
	if (c < 0)
		c = c % 128 + 128;
	while (n > 0)
	{
		if (*search == c)
			return (search);
		search++;
		n--;
	}
	return (NULL);
}
