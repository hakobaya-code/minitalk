/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobaya <hakobaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 17:09:00 by hakobaya          #+#    #+#             */
/*   Updated: 2023/06/10 08:43:26 by hakobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*cpy;
	size_t	s_len;
	size_t	i;

	if (s == NULL)
		return (NULL);
	s_len = ft_strlen(s);
	if (s_len < start)
		len = 0;
	if (s_len - start < len)
		len = s_len - start;
	cpy = ft_calloc(len + 1, sizeof(char));
	if (!(cpy))
		return (NULL);
	i = 0;
	while (i < len && s != '\0')
	{
		cpy[i] = s[start];
		i++;
		start++;
	}
	cpy[i] = '\0';
	return (cpy);
}

//#include <stdio.h>
//
//void	test(char const *s, unsigned int start, size_t len)
//{
//	char	*ret;

//	printf("\ns:%s start: %d, len %d\n", s, start, len);
//	ret = ft_substr(s, start, len);
//	printf("ret [%s]\n", ret);
//}

//int	main(void)
//{
//	test("123", 1, 2);
//	test("123456", 1, 2);
//	test("libft-test-tokyo", 20, 100);
//}