/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waalexan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 16:52:32 by waalexan          #+#    #+#             */
/*   Updated: 2024/05/19 18:12:39 by waalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intlen(int n)
{
	int		size;

	size = 0;
	while (n)
	{
		n /= 10;
		size++;
	}
	return (size);
}

static unsigned int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

char	*ft_itoa(int n)
{
	size_t	num;
	int		size;
	char	*retorno;

	size = ft_intlen(n);
	if (n <= 0)
		size++;
	retorno = (char *)malloc(sizeof(char) * (size + 1));
	if (!retorno)
		return (NULL);
	retorno[size] = '\0';
	if (n == 0)
		retorno[0] = '0';
	num = ft_abs(n);
	if (n < 0)
		retorno[0] = '-';
	while (num)
	{
		retorno[--size] = (num % 10) + '0';
		num /= 10;
	}
	return (retorno);
}
