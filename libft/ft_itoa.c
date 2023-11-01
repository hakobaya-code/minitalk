/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobaya <hakobaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 04:46:53 by hakobaya          #+#    #+#             */
/*   Updated: 2023/06/10 07:39:02 by hakobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

//void	*ft_calloc(size_t count, size_t size)
//{
//	char	*get;
//	size_t	i;
//	size_t	sum;

//	i = 0;
//	sum = count * size;
//	if (size != 0 && count >= SIZE_T_MAX / size)
//		return (NULL);
//	get = (char *)malloc(sizeof(char) * sum);
//	if (!get)
//		return (NULL);
//	while (sum > 0)
//	{
//		get[i] = 0;
//		i++;
//		sum--;
//	}
//	return (get);
//}

char	*put_numarray(char *num_array, int digit, long num, int flag)
{
	int	i;

	i = 0;
	if (flag == -1)
		num_array[0] = '-';
	num_array[digit] = '\0';
	if (num == 0)
	{
		num_array[0] = '0';
		num_array[1] = '\0';
	}
	while (num > 0)
	{
		i = num % 10;
		num /= 10;
		num_array[digit - 1] = i + '0';
		digit--;
	}
	return (num_array);
}

int	check_digit(long num, int flag)
{
	int	digit;

	digit = 1;
	while (num / 10 != 0)
	{
		num /= 10;
		digit++;
	}
	if (flag == -1)
		digit++;
	return (digit);
}

char	*ft_itoa(int n)
{
	char	*num_array;
	int		i;
	int		digit;
	long	num;
	int		flag;

	i = 0;
	num = (long)n;
	flag = 1;
	if (n < 0)
	{
		flag *= -1;
		num *= -1;
	}
	digit = check_digit(num, flag);
	num_array = ft_calloc(digit + 1, sizeof(char));
	if (!num_array)
		return (NULL);
	num_array = put_numarray(num_array, digit, num, flag);
	return (num_array);
}

//int	main(void)
//{
//	printf("%s\n", ft_itoa(0));
//	printf("%s\n", ft_itoa(-0));
//	printf("%s\n", ft_itoa(+0));
//	printf("%s\n", ft_itoa(1));
//	printf("%s\n", ft_itoa(-1));
//	printf("%s\n", ft_itoa(+1));
//	printf("%s\n", ft_itoa(7));
//	printf("%s\n", ft_itoa(-7));
//	printf("%s\n", ft_itoa(+7));
//	printf("%s\n", ft_itoa(42));
//	printf("%s\n", ft_itoa(-42));
//	printf("%s\n", ft_itoa(+42));
//	printf("%s\n", ft_itoa(2147483647));
//	printf("%s\n", ft_itoa(-2147483648));
//	printf("%s\n", ft_itoa(2147483646));
//	printf("%s\n", ft_itoa(-2147483647));
//	return (0);
//}
