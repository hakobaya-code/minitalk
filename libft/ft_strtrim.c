/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobaya <hakobaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 04:27:43 by hakobaya          #+#    #+#             */
/*   Updated: 2023/06/10 07:31:51 by hakobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	search(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (s1[i] != '\0')
	{
		j = 0;
		while (s1[i] != set[j] && set[j] != '\0')
			j++;
		if (set[j] == '\0')
			break ;
		i++;
	}
	return (i);
}

static size_t	rev_search(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	s1len;
	size_t	setlen;

	i = 0;
	s1len = ft_strlen(s1) - 1;
	setlen = ft_strlen(set) - 1;
	while (i < ft_strlen(s1))
	{
		j = 0;
		while (j < ft_strlen(set) && s1[s1len - i] != set[setlen - j])
			j++;
		if (j == ft_strlen(set))
			break ;
		i++;
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trimmed;
	size_t	start;
	size_t	last;
	size_t	len;
	size_t	i;

	if (s1 == NULL || set == NULL)
		return (NULL);
	start = search(s1, set);
	last = rev_search(s1, set);
	if (ft_strlen(s1) == last)
		last = 0;
	len = ft_strlen(s1) - start - last;
	trimmed = ft_calloc(len + 1, sizeof(char));
	if (!trimmed)
		return (NULL);
	i = 0;
	while (s1[start] != '\0' && i < len)
	{
		trimmed[i] = s1[start];
		i++;
		start++;
	}
	trimmed[i] = '\0';
	return (trimmed);
}

//int	main(void)
//{
//	char	*s1;
//	char	*s2;
//	char	*ret;

//	s1 = "  \t \t \n   \n\n\n\t";
//	s2 = "";
//	ret = ft_strtrim(s1, " \n\t");
//	printf("[%s]\n", ret);
//}

//int	main(void)
//{
//	printf("%s\n", ft_strtrim("hello world", "world"));
//	printf("%s\n", ft_strtrim("hello world", "hello"));
//	printf("%s\n", ft_strtrim("hello world", ""));
//	printf("%s\n", ft_strtrim("", ""));
//	printf("%s\n", ft_strtrim(",,,hello,,,world,,,42,,,tokyo,,,,", ","));
//	printf("%s\n", ft_strtrim("    hello world     ", " "));
//	printf("%s\n", ft_strtrim(" \n\t\r    hello \n\t\r world     \r\t\n\t \r\n",
//				" \n\t\r"));
//	printf("%s\n", ft_strtrim("hello world", "abcdefghijklmnopqrstuvwxyz"));
//	//test("hello world", "world");
//	//test("hello world", "hello");
//	//test("hello world", "");
//	//test("", "");
//	//test("    hello world     ", " ");
//	//test(" \n\t\r    hello \n\t\r world     \r\t\n\t \r\n", " \n\t\r");
//	//test("hello world", "abcdefghijklmnopqrstuvwxyz");
//}
