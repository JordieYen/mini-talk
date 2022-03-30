/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jking-ye <jking-ye@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 12:09:27 by jking-ye          #+#    #+#             */
/*   Updated: 2022/03/29 12:16:21 by jking-ye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>

// #include "../libft/ft_atoi.c"
// #include "../libft/ft_putnbr_fd.c"
// #include "../libft/ft_putstr_fd.c"
// #include "../libft/ft_putchar_fd.c"

void	binaryreceiver(int signum)
{
	static int	c;
	static int	i;

	if (signum == SIGUSR1)
		c += 0;
	else if (signum == SIGUSR2)
		c += 128;
	if (i < 7)
		c >>= 1;
	i++;
	if (i == 8)
	{
		write(1, &c, 1);
		c = 0;
		i = 0;
	}
}

int	main(void)
{
	int					pid;

	signal(SIGUSR1, binaryreceiver);
	signal(SIGUSR2, binaryreceiver);
	ft_putstr_fd("Server : Waiting for signals\n", 1);
	pid = getpid();
	ft_putstr_fd("PID : ", 1);
	ft_putnbr_fd(pid, 1);
	ft_putchar_fd('\n', 1);
	while (1)
		pause();
	return (0);
}
