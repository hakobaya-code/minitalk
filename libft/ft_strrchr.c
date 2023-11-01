/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobaya <hakobaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 05:06:55 by hakobaya          #+#    #+#             */
/*   Updated: 2023/06/10 08:30:38 by hakobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t			i;
	size_t			size;
	char			*str;
	unsigned char	c1;

	str = (char *)s;
	c1 = (unsigned char)c;
	if (*s == '\0' && c1 != 0)
		return (NULL);
	if (c1 == '\0')
	{
		i = ft_strlen(str);
		return (&str[i]);
	}
	size = ft_strlen(str) - 1;
	while (str[size] != c1 && size > 0)
		size--;
	if (str[size] == c1)
		return (&str[size]);
	return (NULL);
}

//#include <stdio.h>
//#include <string.h>

//int	main(void)
//{
//	char	*a;

//	a = "a~sdfghzjk~il";
//	printf("%s %s\n", ft_strrchr(a, 'l'), strrchr(a, 'l'));
//	printf("%s %s\n", ft_strrchr(a, 'i'), strrchr(a, 'i'));
//	printf("%s %s\n", ft_strrchr(a, 'b'), strrchr(a, 'b'));
//	printf("%s %s\n", ft_strrchr(a, 'f'), strrchr(a, 'f'));
//	printf("%s %s\n", ft_strrchr(a, 't'), strrchr(a, 't'));
//	printf("%s %s\n", ft_strrchr(a, 'l' + 256), strrchr(a, 'l' + 256));
//	printf("%s %s\n", ft_strrchr(a, 'l' - 256), strrchr(a, 'l' - 256));
//	printf("%s %s\n", ft_strrchr(a, 'z'), strrchr(a, 'z'));
//	printf("%s %s\n", ft_strrchr(a, '~'), strrchr(a, '~'));
//}