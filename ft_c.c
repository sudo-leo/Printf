/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larmelli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 17:04:17 by larmelli          #+#    #+#             */
/*   Updated: 2021/02/25 17:04:22 by larmelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libftprintf.h"

int	ft_print_c(t_flags *flags, va_list ap)
{
	int		count;
	int		x;
	char	c;

	x = va_arg(ap, int);
	c = (char)x;
	count = 0;
	if (flags->width > 0)
	{
		if (flags->minus == 1)
		{
			count += write(1, &c, 1);
			count += ft_print_space(flags->width - 1);
		}
		else
		{
			count += ft_print_space(flags->width - 1);
			count += write(1, &c, 1);
		}
	}
	else
		count += write(1, &c, 1);
	return (count);
}
