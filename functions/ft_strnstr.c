/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waalexan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 10:31:00 by waalexan          #+#    #+#             */
/*   Updated: 2024/05/16 13:38:07 by waalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*h;
	char	*n;
	size_t	l;

	if (*little == 0)
		return ((char *)big);
	n = (char *)little;
	while (*big && len > 0)
	{
		h = (char *)big;
		l = len;
		while (*big && *little && *big == *little && len-- > 0)
		{
			big++;
			little++;
		}
		if (!*little)
			return (h);
		big = ++h;
		little = n;
		len = --l;
	}
	return (NULL);
}
