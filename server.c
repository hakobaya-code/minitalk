/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobaya <hakobaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 06:03:44 by hakobaya          #+#    #+#             */
/*   Updated: 2023/11/01 20:25:22 by hakobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	signal_handler(int signum, siginfo_t *info, void *context)
{
	return (0);
}

int	main(void)
{
	struct sigaction	act;
	sigemptyset(&act.sa_mask);
	act.sa_sigaction = signal_handler;

	//write(1, "hello\n", 6);
	return (0);
}
