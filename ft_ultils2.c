/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larmelli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 17:07:02 by larmelli          #+#    #+#             */
/*   Updated: 2021/02/25 17:07:06 by larmelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libftprintf.h"

int	ft_puts(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
	return (i);
}

int	ft_putnbr(int nb)
{
	int count;

	count = 0;
	if (nb < 0)
		nb = -nb;
	if (nb >= 10)
	{
		count += ft_putnbr(nb / 10);
		count += ft_putnbr(nb % 10);
	}
	else
		count += ft_putchar(nb + '0');
	return (count);
}

int	ft_putchar(char s)
{
	write(1, &s, 1);
	return (1);
}

int	ft_check(int c)
{
	if (c == 'd' || c == 'i' || c == 'u' || c == 'x')
		return (1);
	if (c == 'X' || c == 's' || c == 'p' || c == 'c')
		return (1);
	if (c == '%')
		return (1);
	return (0);
}

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || c == '%')
		return (1);
	return (0);
}
