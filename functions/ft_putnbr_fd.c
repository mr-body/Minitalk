/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waalexan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 10:24:59 by waalexan          #+#    #+#             */
/*   Updated: 2024/06/21 12:28:26 by waalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_color_local(char text, char *color_code);

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	nbr;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		nbr = (unsigned int)(-n);
	}
	else
		nbr = (unsigned int)n;
	if (nbr >= 10)
		ft_putnbr_fd(nbr / 10, fd);
	ft_color_local((char)(nbr % 10 + '0'), "\033[1;32m");
}

void	ft_color_local(char text, char *color_code)
{
	const char	*reset_color_code;

	reset_color_code = "\033[0m";
	write(STDOUT_FILENO, color_code, 7);
	write(STDOUT_FILENO, &text, 1);
	write(STDOUT_FILENO, reset_color_code, 4);
}
