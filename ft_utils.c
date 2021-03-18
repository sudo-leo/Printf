/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larmelli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 17:07:48 by larmelli          #+#    #+#             */
/*   Updated: 2021/02/25 17:07:53 by larmelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libftprintf.h"

int		ft_isdigit(int c)
{
	unsigned char x;

	x = (unsigned char)c;
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (*s != 0)
	{
		i++;
		s++;
	}
	return (i);
}

int		ft_putstr(char *s)
{
	int i;

	if (!s)
		return (0);
	write(1, s, ft_strlen(s));
	i = ft_strlen(s);
	return (i);
}

int		ft_print_zero(int n)
{
	int i;

	i = 0;
	while (n--)
	{
		write(1, "0", 1);
		i++;
	}
	return (i);
}

int		ft_print_space(int n)
{
	int i;

	i = 0;
	while (n--)
	{
		write(1, " ", 1);
		i++;
	}
	return (i);
}
