/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakobaya <hakobaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 18:26:12 by hakobaya          #+#    #+#             */
/*   Updated: 2023/11/07 22:46:56 by hakobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stdio.h>
# include <stdlib.h>
# include <signal.h>
# include <unistd.h>
# include "libft/libft.h"

void	signal_handler(int signum, siginfo_t *info, void *context);
void	signal_handler_client(int signum, siginfo_t *info, void *context);
void	send_string(const pid_t pid, char *str);
void	send_char(const pid_t pid, char c);

#endif