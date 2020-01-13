/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgouacid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 15:57:54 by kgouacid          #+#    #+#             */
/*   Updated: 2020/01/13 15:22:37 by kgouacid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h> //remov&@

# define TYPE_FIELD "cspdiuxX%"
# define FLAGS "0-*."

typedef struct	s_flags
{
	int dot;
	int dash;
	int zero;
	int min;
	int max;
}				t_flags;

void			ft_putchar(char c);
void			ft_putnchar(char c, int n);
void			ft_putstr(char *s);
void			ft_putnstr(char *s, int n);
void			ft_move(char *s1, char *s2);
void			init_flags(va_list args, t_flags *flags, char *rest, int dont_ignore_0);
void			init_flags_p1(t_flags *flags, char *s_flags);
void			init_flags_p2(t_flags *flags, char *rest, int i, int *nb);
void			ft_reset_flags(t_flags *flags);
char			*ft_strndup(const char *s, int n);
int				ft_printf(const char *string, ...);
int				ft_strlen(const char *s);
int				ft_index(char *haystack, char needle);
int				ft_nindex(char *haystack, char needle, int n);
int				ft_putnbr(long n);
int				ft_putnbr_u(unsigned int n);
int				ft_putnbr_base(long n, char *base);
int				ft_int_len(int n);
int				ft_u_len(unsigned int n);
int				ft_len_base(long l, int base);
int				zero_flag(char *s);
int				init_functions(int (*functions[]) (va_list, t_flags));
int				parse(char *rest, va_list args, int *len);

int				ft_print_c(va_list args, t_flags flags);
int				ft_print_s(va_list args, t_flags flags);
int				ft_print_p(va_list args, t_flags flags);
int				ft_print_d(va_list args, t_flags flags);
int				ft_print_i(va_list args, t_flags flags);
int				ft_print_u(va_list args, t_flags flags);
int				ft_print_x(va_list args, t_flags flags);
int				ft_print_x_2(va_list args, t_flags flags);
int				ft_print_p_c(va_list args, t_flags flags);

int				get_dot_zero(t_flags flags, int *len, int nb);
int				get_space(t_flags flags, int new_len, int nb);

#endif
