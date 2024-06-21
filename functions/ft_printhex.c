/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waalexan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 09:54:26 by waalexan          #+#    #+#             */
/*   Updated: 2024/05/23 15:45:07 by waalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printhex(unsigned long n, int type)
{
	char	*digits;
	int		len;

	len = 0;
	if (type)
		digits = "0123456789ABCDEF";
	else
		digits = "0123456789abcdef";
	if (n >= 16)
		len += ft_printhex(n / 16, type);
	ft_putchar(digits[n % 16]);
	len++;
	return (len);
}
