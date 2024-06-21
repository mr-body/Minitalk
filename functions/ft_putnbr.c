/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waalexan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 10:34:29 by waalexan          #+#    #+#             */
/*   Updated: 2024/05/23 15:46:37 by waalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(long n)
{
	long		nbr;
	int			len;

	nbr = 0;
	len = 0;
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		nbr = -n;
		ft_putchar('-');
		len++;
	}
	else
		nbr = n;
	if (nbr >= 10)
		len += ft_putnbr(nbr / 10);
	ft_putchar(nbr % 10 + 48);
	len++;
	return (len);
}
