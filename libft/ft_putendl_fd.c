/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobaya <hakobaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 23:45:39 by hakobaya          #+#    #+#             */
/*   Updated: 2023/06/08 05:57:04 by hakobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	int		len;

	if (s == NULL)
		return ;
	len = ft_strlen(s);
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}
