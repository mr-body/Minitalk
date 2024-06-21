/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waalexan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 16:31:23 by waalexan          #+#    #+#             */
/*   Updated: 2024/06/21 13:08:43 by waalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk_bonus.h"

void	clear(void)
{
	const char	*clear_screen;

	clear_screen = "\033[H\033[2J";
	write(STDOUT_FILENO, clear_screen, ft_strlen(clear_screen));
}

void	ft_handle_signal(int signum, siginfo_t *info, void *context)
{
	static unsigned char	character = 0;
	static int				bit_count = 0;
	static pid_t			client_pid = 0;

	(void)context;
	if (client_pid != info->si_pid)
	{
		bit_count = 0;
		character = 0;
	}
	client_pid = info->si_pid;
	character = character << 1;
	if (signum == SIGUSR1)
		character = character | 1;
	bit_count++;
	if (bit_count == 8)
	{
		write(1, &character, 1);
		if (character == '\0')
			write(1, "\n", 1);
		bit_count = 0;
		character = 0;
	}
	kill(client_pid, SIGUSR2);
}

void	header(void)
{
	clear();
	ft_printf("             ++++++++  +++++++++++++\n");
	ft_printf("           ++++++++    +++++ +++++++\n");
	ft_printf("         ++++++++      +++   +++++++\n");
	ft_printf("       ++++++++        ++    +++++++\n");
	ft_printf("     ++++++++              ++++++++\n");
	ft_printf("   +++++++++             +++++++++\n");
	ft_printf(" +++++++++             +++++++++\n");
	ft_printf("+++++++++++++++++++++  +++++++     +     ++\n");
	ft_printf("+++++++++++++++++++++  +++++++  ++++     ++  L U A N D A\n");
	ft_printf("+++++++++++++++++++++  +++++++ +++++     ++  user: waalexan\n");
	ft_printf("             ++++++++  +++++++++++++     ++\n");
	ft_printf("             ++++++++ 		 			\n");
	ft_printf("             ++++++++ 	minitalk\n");
	ft_printf("             +++++++    Server PID: ");
	ft_putnbr_fd(getpid(), 1);
	ft_color("\n--------------MENSAGENS ENVIADAS-------------\n", "\033[1;33m");
}

int	main(void)
{
	struct sigaction	sa;

	header();
	sa.sa_sigaction = &ft_handle_signal;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		;
	return (0);
}
