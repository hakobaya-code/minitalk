/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobaya <hakobaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 17:01:52 by hakobaya          #+#    #+#             */
/*   Updated: 2023/06/10 10:12:20 by hakobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	min(const char *a, size_t b)
{
	size_t	len;

	len = ft_strlen(a);
	if (len < b)
		return (len);
	else
		return (b);
}

static size_t	comp(const char *haystack, const char *needle, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (haystack[i] != needle[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		i;

	if (haystack == NULL && len == 0)
		return (NULL);
	if (ft_strlen(haystack) < ft_strlen(needle))
		return (NULL);
	if (ft_strlen(needle) == 0)
		return ((char *)haystack);
	if (len == 0)
		return (0);
	i = 0;
	while (i < len)
	{
		if (haystack[i] == *needle)
		{
			if (min(needle, len - i) < ft_strlen(needle))
				return (NULL);
			if ((comp(&haystack[i], needle, ft_strlen(needle))) == 0)
				return ((char *)(haystack + i));
		}
		i++;
	}
	return (NULL);
}

//int	main(void)
//{
//	const char	*largestring;
//	const char	*smallstring;
//	char		*ptr;

//	largestring = "Foo Bar Baz";
//	smallstring = "Bar";
//	ptr = ft_strnstr(NULL, "is", 0);
//	printf("%s\n", ptr);
//	ptr = ft_strnstr(largestring, smallstring, 5);
//	printf("%s\n", ptr);
//	ptr = ft_strnstr(largestring, smallstring, 7);
//	printf("%s\n", ptr);
//	ptr = ft_strnstr("abbbcdefg", "bbc", 20);
//	printf("%s\n", ptr);
//}
