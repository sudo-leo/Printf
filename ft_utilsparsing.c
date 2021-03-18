/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utilsparsing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larmelli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 17:08:57 by larmelli          #+#    #+#             */
/*   Updated: 2021/02/25 17:09:01 by larmelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libftprintf.h"

void	ft_init_width(t_flags *flags, const char *format, va_list ap)
{
	if (format[flags->i] == '*')
	{
		flags->width = va_arg(ap, int);
		if (flags->width < 0)
		{
			flags->minus = 1;
			flags->width = -(flags->width);
		}
		flags->i++;
	}
	else if (ft_isdigit(format[flags->i]))
		while (ft_isdigit(format[flags->i]))
			flags->width = flags->width * 10 + ((int)(format[flags->i++] - 48));
}

void	ft_init_prec(t_flags *flags, const char *format, va_list ap)
{
	flags->prec = 0;
	flags->i++;
	if (format[flags->i] == '*')
	{
		flags->prec = va_arg(ap, int);
		if (flags->prec < 0)
			flags->prec = -1;
		flags->i++;
	}
	else if (ft_isdigit(format[flags->i]))
		while (ft_isdigit(format[flags->i]))
			flags->prec = flags->prec * 10 + ((int)(format[flags->i++] - 48));
}

void	ft_parsing(const char *format, t_flags *flags, va_list ap)
{
	while (format[flags->i] == '-' || format[flags->i] == '0')
	{
		if (format[flags->i] == '-')
			flags->minus = 1;
		if (format[flags->i] == '0')
			flags->zero = 1;
		flags->i++;
	}
	if (format[flags->i] == '*' || ft_isdigit(format[flags->i]))
		ft_init_width(flags, format, ap);
	if (format[flags->i] == '.' && (format[flags->i + 1] == '*' ||
				ft_isdigit(format[flags->i + 1])))
		ft_init_prec(flags, format, ap);
	if (format[flags->i] == '.' && ft_check(format[flags->i + 1]))
		ft_init_prec(flags, format, ap);
	else
		while (!ft_isalpha(format[flags->i]))
			flags->i++;
	flags->type = format[flags->i];
}

int		ft_iterformat2(const char *s, int x)
{
	if (s[x] == '*')
		x++;
	else
	{
		while (ft_isdigit(s[x]))
			x++;
	}
	return (x);
}

int		ft_iterformat(const char *s, int i)
{
	int x;

	x = i + 1;
	while (s[x] == '-' || s[x] == '0')
		x++;
	if (s[x] == '*' || ft_isdigit(s[x]))
	{
		if (s[x] == '*')
			x++;
		else
			while (ft_isdigit(s[x]))
				x++;
	}
	if (s[x] == '.')
		x++;
	if (s[x] == '*' || ft_isdigit(s[x]))
		x = ft_iterformat2(s, x);
	if (ft_check(s[x]))
		return (x);
	return (0);
}
