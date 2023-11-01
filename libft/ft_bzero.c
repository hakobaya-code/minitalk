/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobaya <hakobaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 04:08:57 by hakobaya          #+#    #+#             */
/*   Updated: 2023/06/03 23:29:28 by hakobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	int		i;
	char	*buf;

	i = 0;
	buf = (char *)s;
	while (n > 0)
	{
		buf[i] = 0;
		i++;
		n--;
	}
}

//int	main(void)
//{
//	char str1[] = "abcdefghi";
//	char str2[] = "abcdefghi";
//	bzero(str1, 4);
//	printf("%c\n", *str1);
//	ft_bzero(str2, 4);
//	printf("%c\n", *str2);
//}