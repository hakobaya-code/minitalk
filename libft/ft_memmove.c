/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobaya <hakobaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 04:42:45 by hakobaya          #+#    #+#             */
/*   Updated: 2023/05/31 23:04:27 by hakobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*revmove(void *dst, const void *src, size_t len)
{
	size_t		i;
	char		*dest;
	const char	*source;

	i = len - 1;
	dest = (char *)dst;
	source = (const char *)src;
	while (i >= 0)
	{
		dest[i] = source[i];
		if (i == 0)
			break ;
		i--;
	}
	return (dst);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t		i;
	char		*dest;
	const char	*source;

	i = 0;
	dest = (char *)dst;
	source = (const char *)src;
	if (!dst && !src)
		return (NULL);
	if (len == 0)
		return (dst);
	if (dest > source)
		return (revmove(dst, src, len));
	else
	{
		while (i < len)
		{
			dest[i] = source[i];
			i++;
		}
	}
	return (dst);
}

//#include <stdio.h>
//#include <string.h>

//int	main(void)
//{
//	char str[] = "abcdefghijklmnopqrstu";

//	printf("移動前：%s\n", str);

//	ft_memmove(str + 5, str, 10); /* 重複エリアのコピー */
//	printf("移動後：%s\n", str);

//	return (0);
//}
