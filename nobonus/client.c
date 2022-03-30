/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jking-ye <jking-ye@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 12:06:06 by jking-ye          #+#    #+#             */
/*   Updated: 2022/03/29 12:16:26 by jking-ye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>

// #include "../libft/ft_atoi.c"
// #include "../libft/ft_putnbr_fd.c"
// #include "../libft/ft_putstr_fd.c"
// #include "../libft/ft_putchar_fd.c"

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
			{
				kill(pid, SIGUSR1);
				usleep(400);
			}
			else
			{
				kill(pid, SIGUSR2);
				usleep(400);
			}
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
		ft_putstr_fd("Sending signals\n", 1);
		sendbin(pid, str);
		ft_putstr_fd("Signals sent\n", 1);
	}
	return (0);
}
