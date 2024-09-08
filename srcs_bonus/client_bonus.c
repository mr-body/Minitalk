/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waalexan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 16:50:46 by waalexan          #+#    #+#             */
/*   Updated: 2024/06/20 16:51:20 by waalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk_bonus.h"

static int	g_interroptor = 0;

static void	ft_get_flag(int signum)
{
	g_interroptor = 1;
	(void)signum;
}

static void	ft_write_signal(int pid, unsigned char c)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if ((c >> i) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		while (!g_interroptor)
			;
		g_interroptor = 0;
		i--;
	}
}

int	main(int ac, char **av)
{
	pid_t	pid;
	char	*str;

	str = av[2];
	if (ac != 3)
	{
		ft_putstr("./client [IPID] [MENSAGEM]\n");
		return (0);
	}
	pid = ft_atoi(av[1]);
	if (pid <= 0)
	{
		ft_putstr("PID invalido\n");
		return (0);
	}
	signal (SIGUSR2, ft_get_flag);
	while (*str)
		ft_write_signal(pid, *str++);
	ft_write_signal(pid, '\0');
	return (0);
}
