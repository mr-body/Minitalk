/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waalexan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 16:41:26 by waalexan          #+#    #+#             */
/*   Updated: 2024/05/16 16:52:43 by waalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (nmemb != 0 && size > 4294967295 / nmemb)
		return (NULL);
	ptr = malloc(nmemb * size);
	if (!ptr)
		return (ptr);
	ft_memset((unsigned char *)ptr, 0, nmemb * size);
	return (ptr);
}
