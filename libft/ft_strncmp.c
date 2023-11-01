/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobaya <hakobaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 06:51:28 by hakobaya          #+#    #+#             */
/*   Updated: 2023/05/28 06:47:50 by hakobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	c1;
	unsigned char	c2;

	i = 0;
	if (n == 0)
		return (0);
	c1 = (unsigned char)*s1;
	c2 = (unsigned char)*s2;
	while (c1 == c2 && i < n && c1 != '\0' && c2 != '\0')
	{
		c1 = (unsigned char)*s1++;
		c2 = (unsigned char)*s2++;
		i++;
	}
	return (c1 - c2);
}

//int	ft_strncmp(const char *s1, const char *s2, size_t n)
//{
//	size_t			i;
//	unsigned char	c1;
//	unsigned char	c2;

//	if (n == 0)
//		return (0);
//	i = 0;
//	while (i < n)
//	{
//		c1 = (unsigned char)*s1++;
//		c2 = (unsigned char)*s2++;
//		if (c1 == '\0' || c2 == '\0' || c1 != c2)
//			break ;
//		i++;
//	}
//	return (c1 - c2);
//}

//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//#include <stddef.h>

//int	main(void)
//{
//	char *str = "libft-test-tokyo";
//	char *cmp = "libft-test-tokyo";
//	int	len = strlen(str);
//	/* 1 ~ 17 */
//	for (int i = 0; i <= len; i++)
//		printf("%d %d\n", ft_strncmp(str, cmp, i), strncmp(str, cmp, i));
//	/* 18 ~ 51 */
//	for (int i = 0; i <= len; i++)
//	{
//		cmp = strndup(str, i);
//		printf("%d %d\n", ft_strncmp(str, cmp, i), strncmp(str, cmp, i));
//		printf("%d %d\n", ft_strncmp(str, cmp, len), strncmp(str, cmp, len));
//		free(cmp);
//	}
//	char *cmp2 = calloc(10, 1);
//	strlcpy(cmp2, "libft", 10);
//	cmp2[5] = 0;
//	printf("%d %d\n", ft_strncmp(str, cmp2, len), strncmp(str, cmp2, len));
//	cmp2[5] = -42;
//	printf("%d %d\n", ft_strncmp(str, cmp2, len), strncmp(str, cmp2, len));
//	cmp2[5] = -128;
//	printf("%d %d\n", ft_strncmp(str, cmp2, len), strncmp(str, cmp2, len));
//	cmp2[5] = 42;
//	printf("%d %d\n", ft_strncmp(str, cmp2, len), strncmp(str, cmp2, len));
//	cmp2[5] = 127;
//	printf("%d %d\n", ft_strncmp(str, cmp2, len), strncmp(str, cmp2, len));
//	printf("%d %d\n", ft_strncmp("hello", NULL, 0), strncmp("hello", NULL, 0));
//	printf("%d %d\n", ft_strncmp(NULL, "hello", 0), strncmp(NULL, "hello", 0));
//	printf("%d %d\n", ft_strncmp(NULL, NULL, 0), strncmp(NULL, NULL, 0));
//	return (0);
//}