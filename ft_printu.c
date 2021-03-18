/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larmelli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 17:06:28 by larmelli          #+#    #+#             */
/*   Updated: 2021/02/25 17:06:33 by larmelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libftprintf.h"

int	ft_lenint(int n)
{
	int	i;

	i = 1;
	while (n / 10 != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

int	ft_flags_u3(t_flags *flags, int nb, int len, int count)
{
	count += ft_print_zero(flags->prec - len);
	count += ft_putstr(ft_cast_u(nb));
	return (count);
}

int	ft_flags_u(t_flags *flags, int nb, int len)
{
	int count;

	count = 0;
	if (flags->prec > len)
		count = ft_flags_u3(flags, nb, len, count);
	if (flags->width >= len && flags->prec <= len)
	{
		if (flags->minus == 1)
			count += ft_putstr(ft_cast_u(nb)) +
						ft_print_space(flags->width - len);
		if (flags->zero == 1)
			count += ft_print_zero(flags->width - len) +
						ft_putstr(ft_cast_u(nb));
		else
			count += ft_print_space(flags->width - len) +
						ft_putstr(ft_cast_u(nb));
	}
	else
		count += ft_putstr(ft_cast_u(nb));
	return (count);
}

int	ft_flags_u4(t_flags *flags, int nb, int len, int count)
{
	if (flags->minus == 1)
	{
		count += ft_putnbr(nb);
		count += ft_print_space(flags->width - len);
	}
	else if (flags->zero == 1 && flags->prec == -1)
	{
		count += ft_print_zero(flags->width - len);
		count += ft_putnbr(nb);
	}
	else if (flags->prec >= 0 && flags->zero == 1)
	{
		count += ft_print_space(flags->width - len);
		count += ft_putnbr(nb);
	}
	else
	{
		count += ft_print_space(flags->width - len);
		count += ft_putnbr(nb);
	}
	return (count);
}

int	ft_flags_u2(t_flags *flags, int nb, int len, int count)
{
	count = 0;
	if (flags->width >= len && flags->prec >= len)
	{
		if (flags->minus == 1)
		{
			count += ft_print_zero(flags->prec - len);
			count += ft_putnbr(nb);
			count += ft_print_space(flags->width - flags->prec);
		}
		else
		{
			count += ft_print_space(flags->width - flags->prec);
			count += ft_print_zero(flags->prec - len) + ft_putnbr(nb);
		}
	}
	else if (flags->prec > len)
	{
		count += ft_print_zero(flags->prec - len);
		count += ft_putnbr(nb);
	}
	else if (flags->width >= len && flags->prec <= len)
		count = ft_flags_u4(flags, nb, len, count);
	else
		count += ft_putnbr(nb);
	return (count);
}
