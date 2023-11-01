/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobaya <hakobaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 23:10:45 by hakobaya          #+#    #+#             */
/*   Updated: 2023/06/10 08:15:28 by hakobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*target;
	unsigned int	i;

	if (s == NULL)
		return (NULL);
	target = ft_calloc(ft_strlen(s) + 1, sizeof(char));
	if (!target)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		target[i] = f(i, s[i]);
		i++;
	}
	target[i] = '\0';
	return (target);
}

//#include <stdio.h>

//size_t	ft_strlen(const char *s)
//{
//	int		i;
//	char	*str;
//}

//	i = 0;
//	str = (char *)s;
//	while (s[i] != '\0')
//		i++;
//	return ((size_t) i);
////}

//int main(void)
//{
//	ft_strmapi("asdfgh", to_upper);
//}