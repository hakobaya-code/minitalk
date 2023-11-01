/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobaya <hakobaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 02:39:30 by hakobaya          #+#    #+#             */
/*   Updated: 2023/06/01 04:50:22 by hakobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	cpysize(size_t srcsize, size_t dstsize)
{
	if (srcsize < dstsize)
		return ((int)srcsize);
	return ((int)(dstsize - 1));
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	int		i;
	size_t	srcsize;
	int		copysize;

	if (dstsize == 0)
		return (ft_strlen(src));
	srcsize = ft_strlen(src);
	copysize = cpysize(srcsize, dstsize);
	i = 0;
	while (i < copysize)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (srcsize);
}

//#include <stdio.h>

//int	main(void)
//{
//	char cmd[] = "rm *.bak";
//	char buf[5];
//	size_t confirm;

//	confirm = ft_strlcpy(buf, cmd, sizeof(buf));
//	printf("%s\n", buf);
//	printf("%zu\n", confirm);
//}