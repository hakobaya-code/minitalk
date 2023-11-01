/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobaya <hakobaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 03:08:40 by hakobaya          #+#    #+#             */
/*   Updated: 2023/06/10 07:59:52 by hakobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *buf, int ch, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	ch2;

	str = (unsigned char *)buf;
	ch2 = (unsigned char)ch;
	i = 0;
	while (i < n)
	{
		str[i] = ch2;
		i++;
	}
	return (buf);
}

//int	main(void)
//{
//	char	str[10];

//	str = "0123456789";
//	memset = (str, '*', 5);
//	printf("%s\n", str);
//	ft_memset(str + 2, '*', 5);
//	printf("%s\n", str);
//	return (0);
//}
