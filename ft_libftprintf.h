/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libftprintf.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larmelli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 17:04:38 by larmelli          #+#    #+#             */
/*   Updated: 2021/02/25 17:04:43 by larmelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIBFTPRINTF_H
# define FT_LIBFTPRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct	s_flags
{
	int		prec;
	int		minus;
	int		width;
	char	type;
	int		zero;
	int		neg;
	int		i;
}				t_flags;

int				ft_puts2(char *s, int c);
int				ft_widthpoint(t_flags *flags, char *ris, int i);
char			*reverse1(char *str);
int				ft_putchar(char s);
int				ft_check(int c);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_count(const char *format);
size_t			ft_strlen(const char *s);
int				ft_putstr(char *s);
int				ft_print_zero(int n);
int				ft_print_space(int n);
int				ft_str2(t_flags *flags, char *s);
int				ft_str(t_flags *flags, char *str, int count);
int				ft_print_str(t_flags *flags, va_list ap);
int				ft_print_c(t_flags *flags, va_list ap);
int				ft_x(va_list ap, t_flags *flags, int count);
int				ft_printint(t_flags *flags, va_list ap);
char			*ft_itoa(int n, t_flags *flags);
char			*ft_utoa(int n);
char			*reverse(char *str);
int				ft_printpoint(t_flags *flags, va_list ap);
int				ft_putnbr(int nb);
int				ft_puts(char *s);
char			*ft_convert_x(char *exa);
char			*ft_convert_xx(char *exa);
int				ft_printu(t_flags *flags, va_list ap, int count);
int				ft_lenint(int n);
char			*ft_cast_u(int nb);
char			*ft_removeminus(char *c);
int				ft_int_width(t_flags *flags, char *c, int len);
int				ft_int_widthandprec(t_flags *flags, char *c, int len);
void			ft_init_width(t_flags *flags, const char *format, va_list ap);
void			ft_init_prec(t_flags *flags, const char *format, va_list ap);
void			ft_parsing(const char *format, t_flags *flags, va_list ap);
int				ft_iterformat2(const char *s, int x);
int				ft_iterformat(const char *s, int i);
int				ft_flags_u3(t_flags *flags, int nb, int len, int count);
int				ft_flags_u(t_flags *flags, int nb, int len);
int				ft_flags_u4(t_flags *flags, int nb, int len, int count);
int				ft_flags_u2(t_flags *flags, int nb, int len, int count);
int				ft_nullstring(t_flags *flags);
int				ft_widthpoint3(t_flags *flags, int len, int i, char *ris);

#endif
