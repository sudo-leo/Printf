/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utilsu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larmelli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 17:08:31 by larmelli          #+#    #+#             */
/*   Updated: 2021/02/25 17:08:35 by larmelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libftprintf.h"

char	*ft_cast_u(int nb)
{
	char			*ris;
	unsigned int	n;
	int				i;
	int				x;

	x = 0;
	ris = malloc((sizeof(char) * 10 + 1));
	i = 1000000000;
	n = nb;
	if (nb < 0)
	{
		while (i != 1)
		{
			ris[x] = (((char)(n / i) + '0'));
			n = n - (i * (n / i));
			i = i / 10;
			x++;
		}
		ris[x] = (((char)(n % 10) + '0'));
		ris[x + 1] = 0;
	}
	return (ris);
}

int		ft_printu2(t_flags *flags, int nb, int re, int count)
{
	if (flags->minus == 1)
	{
		count += ft_putnbr(nb);
		count += ft_print_space(flags->width - re);
	}
	else if (flags->zero == 1)
	{
		count += ft_print_zero(flags->width - re);
		count += ft_putnbr(nb);
	}
	else
	{
		count += ft_print_space(flags->width - re);
		count += ft_putnbr(nb);
	}
	return (count);
}

int		ft_printu3(t_flags *flags, int len, int count)
{
	if (flags->minus == 1)
	{
		count += ft_print_zero(flags->prec - len);
		count += ft_print_space(flags->width - flags->prec);
	}
	else
	{
		count += ft_print_space(flags->width - flags->prec);
		count += ft_print_zero(flags->prec - len);
	}
	return (count);
}

int		ft_printu(t_flags *flags, va_list ap, int count)
{
	int nb;
	int len;
	int re;

	count = 0;
	nb = va_arg(ap, int);
	re = ft_lenint(nb);
	len = ft_strlen(ft_cast_u(nb));
	if (nb < 0)
		count += ft_flags_u(flags, nb, len);
	if (nb > 0)
		count = ft_flags_u2(flags, nb, re, count);
	if (nb == 0 && flags->prec == -1 && flags->width == 0)
		count += ft_putnbr(nb);
	if (nb == 0 && flags->prec == 0 && flags->width != 0)
		count += ft_print_space(flags->width);
	if (nb == 0 && flags->width > 0 && flags->prec > 0)
		count = ft_printu3(flags, len, count);
	if (nb == 0 && flags->width > 0 && flags->prec == -1)
		count = ft_printu2(flags, nb, re, count);
	if (nb == 0 && flags->width == 0 && flags->prec > 0)
		count += ft_print_zero(flags->prec - re) + ft_putnbr(nb);
	return (count);
}
