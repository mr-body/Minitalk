/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waalexan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 09:16:29 by waalexan          #+#    #+#             */
/*   Updated: 2024/05/23 13:03:36 by waalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_options(va_list data, const char *s)
{
	if (*s == 'c')
	{
		return (ft_putchar(va_arg(data, int)));
	}
	else if (*s == 's')
		return (ft_putstr(va_arg(data, char *)));
	else if (*s == 'd' || *s == 'i')
		return ((long)ft_putnbr(va_arg(data, int)));
	else if (*s == 'u')
		return (ft_putunsigned(va_arg(data, unsigned int)));
	else if (*s == 'x')
		return (ft_printhex(va_arg(data, unsigned int), 0));
	else if (*s == 'X')
		return (ft_printhex(va_arg(data, unsigned int), 1));
	else if (*s == 'p')
		return (ft_printptr(va_arg(data, void *)));
	else if (*s == '%')
		return (ft_putchar('%'));
	else
		return (-1);
}

int	ft_printf(const char *s, ...)
{
	va_list		data;
	int			len;

	va_start (data, s);
	len = 0;
	while (*s)
	{
		if (*s == '%')
		{
			s++;
			len += ft_options(data, s);
		}
		else
			len += ft_putchar(*s);
		s++;
	}
	va_end(data);
	return (len);
}
