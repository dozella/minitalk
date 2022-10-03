/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dozella <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 02:41:51 by dozella           #+#    #+#             */
/*   Updated: 2022/03/25 04:21:42 by dozella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include "libft/libft.h"

char	*g_line;

void	go(int signum, siginfo_t *siginfo, void *context)
{
	char			c;
	static int		sdvig = 7;
	static pid_t	pid = 0;

	(void) signum;
	(void) context;
	c = *g_line;
	if (!pid)
		pid = siginfo->si_pid;
	if ((c >> sdvig) & 00000001)
		kill(pid, SIGUSR1);
	if (!((c >> sdvig) & 00000001))
		kill(pid, SIGUSR2);
	usleep(60);
	if (sdvig == 0)
	{
		if (!c)
			exit(0);
		sdvig = 7;
		g_line++;
	}
	else
		sdvig--;
}

int	main(int argc, char **argv)
{
	struct sigaction	cl;

	if (argc != 3)
		ft_putstr_fd("Error arguments", 1);
	cl.sa_flags = SA_SIGINFO;
	cl.sa_sigaction = go;
	if (sigaction(SIGUSR1, &cl, NULL) < 0)
		ft_putstr_fd("Error signal", 1);
	g_line = argv[2];
	g_line[ft_strlen(argv[2])] = '\0';
	if (kill(ft_atoi(argv[1]), SIGUSR1) < 0)
		ft_putstr_fd("Error sending", 1);
	while (1)
		pause();
	return (0);
}
