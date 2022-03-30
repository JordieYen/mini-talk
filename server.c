/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jking-ye <jking-ye@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 12:09:27 by jking-ye          #+#    #+#             */
/*   Updated: 2022/03/29 15:38:46 by jking-ye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include "libft/libft.h"

void	binaryreceiver(int signum, siginfo_t *info, void *context)
{
	static int	c;
	pid_t		pid;
	static int	i;

	(void)context;
	pid = info->si_pid;
	if (signum == SIGUSR2)
		c += 128;
	if (i < 7)
		c >>= 1;
	i++;
	if (i == 8)
	{
		write(1, &c, 1);
		kill(pid, SIGUSR1);
		c = 0;
		i = 0;
	}
}

int	main(void)
{
	int					pid;
	struct sigaction	sa;

	sa.sa_sigaction = binaryreceiver;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_putstr_fd("Server : Waiting for signals\n", 1);
	pid = getpid();
	ft_putstr_fd("PID : ", 1);
	ft_putnbr_fd(pid, 1);
	ft_putchar_fd('\n', 1);
	while (1)
		pause();
	return (0);
}
