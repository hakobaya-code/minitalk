/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobaya <hakobaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 18:27:10 by hakobaya          #+#    #+#             */
/*   Updated: 2023/05/27 18:01:05 by hakobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	int		i;
	char	*str;

	i = 0;
	str = (char *)s;
	while (s[i] != '\0')
		i++;
	return ((size_t) i);
}

//#include <stdio.h>

//int	main(void)
//{
//	size_t length;
//	char *a = "dfghjk";

//	length = ft_strlen(a);
//	printf("%zu\n", length);
//}
