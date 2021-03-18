/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utilsint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larmelli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 17:08:10 by larmelli          #+#    #+#             */
/*   Updated: 2021/02/25 17:08:15 by larmelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libftprintf.h"

char	*ft_removeminus(char *c)
{
	char	*str;
	int		len;
	int		i;
	int		k;

	k = 0;
	i = 1;
	len = ft_strlen(c);
	if (!(str = malloc(sizeof(char) * len)))
		return (NULL);
	while (c[i])
		str[k++] = c[i++];
	free(c);
	return (str);
}

int		ft_printint3(t_flags *flags, int len, int i, char *c)
{
	if (flags->neg == 1)
		i += ft_putchar('-');
	if (flags->prec > len)
		i += ft_print_zero(flags->prec - len);
	i += ft_puts(c);
	return (i);
}

int		ft_printint2(t_flags *flags, int len, int i, char *c)
{
	if (flags->neg == 1)
		i += ft_putchar('-');
	i += ft_print_zero(flags->prec - len);
	i += ft_puts(c);
	return (i);
}

int		ft_printint4(t_flags *flags, int i, char *c)
{
	if (flags->neg == 1)
		i += ft_putchar('-');
	i += ft_puts(c);
	return (i);
}

int		ft_printint(t_flags *flags, va_list ap)
{
	int		i;
	int		n;
	int		len;
	char	*c;

	i = 0;
	n = va_arg(ap, int);
	c = ft_itoa(n, flags);
	if (flags->prec == 0 && c[0] == '0')
		c[0] = 0;
	if ((flags->minus == 1 && flags->zero == 1))
		flags->zero = 0;
	len = ft_strlen(c);
	if (flags->prec > flags->width && flags->prec > len)
		i = ft_printint2(flags, len, i, c);
	else if (flags->width > len && flags->prec >= len)
		i += ft_int_widthandprec(flags, c, len);
	else if (flags->width > len)
		i += ft_int_width(flags, c, len);
	else if (flags->prec > 0 && flags->width == 0)
		i = ft_printint3(flags, len, i, c);
	else
		i = ft_printint4(flags, i, c);
	return (i);
}
