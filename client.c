/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jking-ye <jking-ye@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 12:06:06 by jking-ye          #+#    #+#             */
/*   Updated: 2022/03/29 15:51:30 by jking-ye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include "libft/libft.h"

void	response(int signum)
{
	if (signum == SIGUSR1)
		ft_putstr_fd("Char recieved\n", 1);
}

void	sendbin(int pid, char *str)
{
	static int	i;
	int			j;
	char		c;

	while (str[i] != '\0')
	{
		c = str[i];
		j = 0;
		while (j < 8)
		{
			if (c % 2 == 0)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(50);
			j++;
			c >>= 1;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int		pid;
	char	*str;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		str = argv[2];
		signal(SIGUSR1, response);
		signal(SIGUSR2, response);
		ft_putstr_fd("Sending signals\n", 1);
		sendbin(pid, str);
	}
	return (0);
}
