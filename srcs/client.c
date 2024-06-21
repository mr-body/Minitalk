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

#include "../includes/minitalk.h"

int	g_config_flag = 0;

void	ft_resp_handler(int signum)
{
	g_config_flag = 1;
	(void)signum;
}

void	ft_send_bit(int pid, int bit)
{
	int	signal;

	if (bit == 1)
		signal = SIGUSR1;
	else
		signal = SIGUSR2;
	if (kill(pid, signal) == -1)
	{
		ft_putstr("error");
		exit(EXIT_FAILURE);
	}
	while (!g_config_flag)
		;
	g_config_flag = 0;
}

void	ft_send_char(int pid, unsigned char c)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		ft_send_bit(pid, (c >> i) & 1);
		usleep(400);
		i--;
	}
}

void	ft_send_string(int pid, const char *str)
{
	while (*str)
		ft_send_char(pid, *str++);
	ft_send_char(pid, '\0');
}

int	main(int ac, char **av)
{
	pid_t	pid;

	if (ac != 3)
	{
		ft_putstr("tens que usar: ./client [IPID] [STRING]\n");
		exit(EXIT_FAILURE);
	}
	pid = ft_atoi(av[1]);
	if (pid <= 0)
	{
		ft_putstr("PID invalido\n");
		exit(EXIT_FAILURE);
	}
	signal (SIGUSR2, ft_resp_handler);
	ft_send_string(pid, av[2]);
	return (0);
}
