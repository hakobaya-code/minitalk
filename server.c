/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobaya <hakobaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 06:03:44 by hakobaya          #+#    #+#             */
/*   Updated: 2023/11/05 20:31:13 by hakobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	signal_handler(int signum, siginfo_t *info, void *context)
{
	static int	digit;
	const char	*str[8];
	int			c;

	printf("%s\n", "signal_handler1");
	digit = 1;
	memset(str, 0, 8);
	while (digit < 8)
	{
		printf("%s\n", "signal_handler2");
		if (signum == SIGUSR1)
		{
			str[8 - digit] = '1';
			printf("%d, %s\n", digit, str);
		}
		else if (signum == SIGUSR2)
		{
			str[8 - digit] = '0';
			printf("%d, %s\n", digit, str);
			//printf("USR2\n");
		}
		digit++;
		printf("%s\n", "signal_handler2-2");
	}
	printf("%s\n", "signal_handler3");
	printf("%s\n", str);
	c = (int)atoi(str);
	printf("%d\n", c);
	printf("%s\n", "signal_handler4");
	write(1, &c, 1);
	//digit = 0;
	//while (digit < )
	//{
	//	if (signum == SIGUSR1)
	//	{
	//	}
	//	else if (signum == SIGUSR2)
	//	{
	//	}
	//	digit--;
	//}
	//return (0);
}

#include <string.h>

int	main(void)
{
	struct sigaction	act;

	memset(&act, 0, sizeof(struct sigaction));
	sigemptyset(&act.sa_mask); // maskをクリアにしている
	act.sa_sigaction = signal_handler; //sigactionが来た時に何を呼び出すかの設定
	act.sa_flags = 0; //これ何か調べる
	printf("%s\n", "server_main1");
	sigaction(SIGUSR1, &act, NULL);
	printf("%s\n", "server_main2");
	sigaction(SIGUSR2, &act, NULL);
	printf("%s\n", "server_main3");
	//while (1)/
		pause();
	//if ()
	//write(1, "hello\n", 6);
	return (0);
}
