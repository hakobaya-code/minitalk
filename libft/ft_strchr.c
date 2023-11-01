/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobaya <hakobaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 03:55:36 by hakobaya          #+#    #+#             */
/*   Updated: 2023/06/10 10:09:06 by hakobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*str;

	i = 0;
	str = (char *)s;
	if (c == '\0')
	{
		i = ft_strlen(str);
		return (&str[i]);
	}
	if (c < 0)
		c = c % 128 + 128;
	if (c > 127)
		c %= 128;
	while (str[i] != c && str[i] != '\0')
		i++;
	if (str[i] == c)
		return (&str[i]);
	return (NULL);
}

//#include <stdio.h>

//int	main(void)
//{
//	char	*a;

//	a = "a~sdfghzjk~il";
//	printf("%s %s\n", ft_strchr(a, 'l'), strchr(a, 'l'));
//	printf("%s %s\n", ft_strchr(a, 'i'), strchr(a, 'i'));
//	printf("%s %s\n", ft_strchr(a, 'b'), strchr(a, 'b'));
//	printf("%s %s\n", ft_strchr(a, 'f'), strchr(a, 'f'));
//	printf("%s %s\n", ft_strchr(a, 't'), strchr(a, 't'));
//	printf("%s %s\n", ft_strchr(a, 'l' + 256), strchr(a, 'l' + 256));
//	printf("%s %s\n", ft_strchr(a, 'l' - 256), strchr(a, 'l' - 256));
//	printf("%s %s\n", ft_strchr(a, 'z'), strchr(a, 'z'));
//	printf("%s %s\n", ft_strchr(a, '~'), strchr(a, '~'));
//}
