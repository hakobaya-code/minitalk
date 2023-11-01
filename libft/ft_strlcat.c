/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobaya <hakobaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 03:19:43 by hakobaya          #+#    #+#             */
/*   Updated: 2023/06/10 07:52:06 by hakobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	d_size;
	size_t	s_size;

	if (dstsize == 0 || dstsize < ft_strlen(dst))
		return (dstsize + ft_strlen(src));
	d_size = ft_strlen(dst);
	s_size = ft_strlen(src);
	i = 0;
	while (d_size + i < dstsize - 1 && src[i] != '\0')
	{
		dst[d_size + i] = src[i];
		i++;
	}
	dst[d_size + i] = '\0';
	return (d_size + s_size);
}

//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>

//int	main(void)
//{
//	char	*dst1 = calloc(100, sizeof(char));
//	char	*dst2 = calloc(100, sizeof(char));
//	char	*src1 = calloc(100, sizeof(char));
//	char	*src2 = calloc(100, sizeof(char));
//	int		i;

//	i = 0;
//	while (i < 99)
//	{
//		src1[i] = i + 1;
//		src2[i] = i + 1;
//		i++;
//	}
//	printf("%lu\n", ft_strlcat(dst1, src1, 0));
//	printf("%lu\n", strlcat(dst2, src2, 0));
//	printf("%lu\n", ft_strlcat(dst1, src1, 10));
//	printf("%lu\n", strlcat(dst2, src2, 10));
//	printf("%lu\n", ft_strlcat(dst1, src1, 50));
//	printf("%lu\n", strlcat(dst2, src2, 50));
//	printf("%lu\n", ft_strlcat(dst1, src1, 100));
//	printf("%lu\n", strlcat(dst2, src2, 100));
//	printf("%lu\n", ft_strlcat(dst1, src1, 10));
//	printf("%lu\n", strlcat(dst2, src2, 10));
//	return(0);
//}
