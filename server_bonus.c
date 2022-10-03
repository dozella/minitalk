/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dozella <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 02:51:21 by dozella           #+#    #+#             */
/*   Updated: 2022/03/26 00:12:56 by dozella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft/libft.h"

void	print_end(char *c, int *a, int *sdvig)
{
	ft_putchar_fd (*c, 1);
	if (!*c)
	{
		*a = 0;
		ft_putchar_fd ('\n', 1);
	}
	*c = 0;
	*sdvig = 0;
}

void	work(int signum, siginfo_t *siginfo, void *context)
{
	static int		sdvig = 0;
	static char		c = 0;
	static pid_t	pid = 0;
	static int		a = 0;

	(void) context;
	pid = siginfo->si_pid;
	if ((signum == SIGUSR1) && (a == 0))
	{
		kill(pid, SIGUSR1);
		a = 1;
		return ;
	}
	if (signum == SIGUSR1)
		c = c | 1;
	if (sdvig++ == 7)
		print_end(&c, &a, &sdvig);
	c = c << 1;
	kill(pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	serv;

	ft_putstr_fd ("Server Pid: ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd ('\n', 1);
	serv.sa_flags = SA_SIGINFO;
	serv.sa_sigaction = work;
	if (sigaction(SIGUSR1, &serv, NULL) < 0)
		ft_putstr_fd("Error signal", 1);
	if (sigaction(SIGUSR2, &serv, NULL) < 0)
		ft_putstr_fd("Error signal", 1);
	while (1)
		pause ();
	return (0);
}
