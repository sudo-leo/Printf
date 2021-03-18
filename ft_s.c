/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larmelli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 17:06:09 by larmelli          #+#    #+#             */
/*   Updated: 2021/02/25 17:06:13 by larmelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libftprintf.h"

int	ft_str2(t_flags *flags, char *s)
{
	int count;

	count = 0;
	if (flags->minus == 1)
	{
		count += ft_putstr(s);
		count += ft_print_space(flags->width - (int)ft_strlen(s));
	}
	else
	{
		count += ft_print_space(flags->width - (int)ft_strlen(s));
		count += ft_putstr(s);
	}
	return (count);
}

int	ft_str(t_flags *flags, char *str, int count)
{
	char	*s;
	int		len;
	int		i;

	count = 0;
	if (flags->prec == 0)
		return (count += ft_print_space(flags->width));
	else
	{
		s = malloc(sizeof(char) * (flags->prec + 1));
		i = 0;
		len = flags->prec;
		while (len--)
		{
			s[i] = str[i];
			i++;
		}
		s[i] = '\0';
	}
	if (flags->width >= 0 && flags->width > (int)ft_strlen(s))
		count += ft_str2(flags, s);
	else
		count += ft_putstr(s);
	return (count);
}

int	ft_print_str(t_flags *flags, va_list ap)
{
	char	*str;
	int		count;

	count = 0;
	if (!(str = va_arg(ap, char*)))
		return (count += ft_nullstring(flags));
	if (flags->prec >= 0 && flags->prec <= (int)ft_strlen(str))
		count += ft_str(flags, str, count);
	else if (flags->width > 0 && flags->width > (int)ft_strlen(str))
	{
		if (flags->minus == 1)
		{
			count += ft_putstr(str);
			count += ft_print_space(flags->width - (int)ft_strlen(str));
		}
		else
		{
			count += ft_print_space(flags->width - (int)ft_strlen(str));
			count += ft_putstr(str);
		}
	}
	else
		count += ft_putstr(str);
	return (count);
}
