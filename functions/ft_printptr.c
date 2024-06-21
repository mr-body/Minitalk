/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waalexan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 11:54:00 by waalexan          #+#    #+#             */
/*   Updated: 2024/05/23 12:20:31 by waalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printptr(void *ptr)
{
	int					len;
	unsigned long		setpoint;

	len = 0;
	if (!ptr)
	{
		len += ft_putstr("(nil)");
	}
	else
	{
		setpoint = (unsigned long)ptr;
		len += ft_putstr("0x");
		len += ft_printhex(setpoint, 0);
	}
	return (len);
}
