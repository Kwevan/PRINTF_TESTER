/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgouacid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 15:57:54 by kgouacid          #+#    #+#             */
/*   Updated: 2020/01/10 17:23:41 by kgouacid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>  //ofc remove this
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

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
void			init_flags(va_list args, t_flags *flags, char *rest);
char			*ft_strndup(const char *s, int n);
int				ft_printf(const char *string, ...);
int				ft_strlen(const char *s);
int				ft_index(char *haystack, char needle);
int				ft_nindex(char *haystack, char needle, int n);
int				ft_putnbr(int n);
int				ft_putnbr_u(unsigned int n);
int				ft_putnbr_base(long n, char *base);
int				ft_int_len(int n);
int				ft_u_len(unsigned int n);
int				ft_len_base(long l, int base);

int				init_functions(int (*functions[]) (va_list, t_flags));
int				parse(char *rest, va_list args);

#endif
