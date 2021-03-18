/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nullstring.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larmelli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 17:07:23 by larmelli          #+#    #+#             */
/*   Updated: 2021/02/25 17:07:27 by larmelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libftprintf.h"

int	ft_snull(int k)
{
	char	s[7];
	int		i;
	int		count;

	i = 0;
	count = 0;
	s[0] = '(';
	s[1] = 'n';
	s[2] = 'u';
	s[3] = 'l';
	s[4] = 'l';
	s[5] = ')';
	s[6] = 0;
	while (k-- && s[i])
	{
		count += ft_putchar(s[i]);
		i++;
	}
	s[i] = 0;
	return (count);
}

int	ft_nullstring4(t_flags *flags, int count)
{
	if (flags->prec == -1)
		count += ft_snull(flags->prec);
	else
	{
		if (flags->minus == 1)
		{
			count += ft_snull(flags->prec);
			count += ft_print_space(flags->width - flags->prec);
		}
		else
		{
			count += ft_print_space(flags->width - flags->prec);
			count += ft_snull(flags->prec);
		}
	}
	return (count);
}

int	ft_nullstring3(t_flags *flags)
{
	int count;

	count = 0;
	if (flags->width > 6 && flags->prec == -1)
	{
		if (flags->minus == 1)
		{
			count += ft_snull(6);
			count += ft_print_space(flags->width - 6);
		}
		else
		{
			count += ft_print_space(flags->width - 6);
			count += ft_snull(6);
		}
	}
	else if (flags->prec > 6)
	{
		count += ft_snull(flags->prec);
		count += ft_print_space(flags->width - 6);
	}
	else
		count = ft_nullstring4(flags, count);
	return (count);
}

int	ft_nullstring2(t_flags *flags)
{
	int count;

	count = 0;
	if (flags->minus == 1 && flags->width < 6)
	{
		if (flags->prec > 6)
		{
			count += ft_snull(flags->prec);
			count += ft_print_space(flags->width - 6);
		}
		else
		{
			if (flags->prec == -1)
				count += ft_snull(flags->prec);
			else if (flags->prec > -1)
			{
				count += ft_snull(flags->prec);
				count += ft_print_space(flags->width - flags->prec);
			}
		}
	}
	else
		count += ft_nullstring3(flags);
	return (count);
}

int	ft_nullstring(t_flags *flags)
{
	int count;

	count = 0;
	if (flags->width > flags->prec)
		count += ft_nullstring2(flags);
	else if (flags->width <= flags->prec)
	{
		if (flags->width < 6)
			count += ft_snull(flags->prec);
		else if (flags->minus == 1)
		{
			count += ft_snull(flags->prec);
			count += ft_print_space(flags->width - 6);
		}
		else
		{
			count += ft_print_space(flags->width - 6);
			count += ft_snull(flags->prec);
		}
	}
	else
		count += ft_snull(flags->prec);
	return (count);
}
