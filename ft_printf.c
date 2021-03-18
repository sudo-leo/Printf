/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larmelli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 17:05:01 by larmelli          #+#    #+#             */
/*   Updated: 2021/02/25 17:05:06 by larmelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libftprintf.h"

int		ft_percent(t_flags *flags, int count)
{
	if (flags->minus == 0)
	{
		count += ft_print_zero(flags->width - 1);
		count += ft_putchar('%');
	}
	else
	{
		count += ft_putchar('%');
		count += ft_print_space(flags->width - 1);
	}
	return (count);
}

int		ft_printpercent(t_flags *flags)
{
	int count;

	count = 0;
	if (flags->width > 1)
	{
		if (flags->minus == 1 || flags->zero == 1)
			count = ft_percent(flags, count);
		else
		{
			count += ft_print_space(flags->width - 1);
			count += ft_putchar('%');
		}
	}
	else
		count += ft_putchar('%');
	return (count);
}

void	ft_init_flags(t_flags *flags, int i)
{
	flags->prec = -1;
	flags->minus = 0;
	flags->width = 0;
	flags->type = 0;
	flags->zero = 0;
	flags->i = i + 1;
}

int		ft_stampa(t_flags *flags, va_list ap)
{
	int count;

	count = 0;
	if (flags->type == 'c')
		count += ft_print_c(flags, ap);
	if (flags->type == 's')
		count += ft_print_str(flags, ap);
	if (flags->type == 'x' || flags->type == 'X')
		count += ft_x(ap, flags, count);
	if (flags->type == 'd' || flags->type == 'i')
		count += ft_printint(flags, ap);
	if (flags->type == 'p')
		count += ft_printpoint(flags, ap);
	if (flags->type == 'u')
		count += ft_printu(flags, ap, count);
	if (flags->type == '%')
		count += ft_printpercent(flags);
	return (count);
}

int		ft_printf(const char *format, ...)
{
	va_list ap;
	int		i;
	int		risultato;
	t_flags flags;

	risultato = 0;
	va_start(ap, format);
	i = 0;
	while (format[i])
	{
		if (format[i] == '%' && ft_iterformat(format, i))
		{
			ft_init_flags(&flags, i);
			ft_parsing(format, &flags, ap);
			risultato += ft_stampa(&flags, ap);
			i = ft_iterformat(format, i);
		}
		else
			risultato += ft_putchar(format[i]);
		i++;
	}
	va_end(ap);
	return (risultato);
}
