/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobaya <hakobaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 23:48:36 by hakobaya          #+#    #+#             */
/*   Updated: 2023/11/07 05:17:14 by hakobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	num;
	long	rem;
	char	minus;

	num = (long)n;
	minus = '-';
	if (num < 0)
	{
		write(fd, &minus, 1);
		num *= -1;
	}
	rem = num % 10;
	if (num / 10 != 0)
		ft_putnbr_fd(num / 10, fd);
	rem = rem + '0';
	write(fd, &rem, 1);
}

//int	main(void)
//{
//	ft_putnbr_fd(-12345, 1);
//}
