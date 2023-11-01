/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobaya <hakobaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 15:04:11 by hakobaya          #+#    #+#             */
/*   Updated: 2023/05/27 18:40:41 by hakobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*cmp1;
	unsigned char	*cmp2;
	int				size;
	int				i;

	cmp1 = (unsigned char *)s1;
	cmp2 = (unsigned char *)s2;
	i = 0;
	size = n;
	while (i < size)
	{
		if (cmp1[i] == cmp2[i])
			i++;
		else
			return (cmp1[i] - cmp2[i]);
	}
	return (0);
}

//int	main(void)
//{
//	char	*s1 = "ASDFGHJK";
//	char	*s2 = "ASDFQWER";
//	int		ans;

//	ans = ft_memcmp((const void *)s1, (const void *)s2, 8);
//	printf("%d\n", ans);
//}
