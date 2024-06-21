/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waalexan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 11:33:47 by waalexan          #+#    #+#             */
/*   Updated: 2024/05/24 11:33:52 by waalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int	ft_putnbr(long int n);
int	ft_putunsigned(unsigned int n);
int	ft_putchar(char c);
int	ft_strprintlen(char *str);
int	ft_printhex(unsigned long n, int type);
int	ft_printf(const char *s, ...);
int	ft_putstr(char *s);
int	ft_printptr(void *ptr);
int	ft_abs(int x);

#endif
