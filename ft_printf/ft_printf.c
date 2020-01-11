/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgouacid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 15:58:03 by kgouacid          #+#    #+#             */
/*   Updated: 2020/01/11 14:47:15 by kgouacid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_print_s(va_list args, t_flags flags)
{
	char	*s;
	int		i;
	int len;
	s = va_arg(args, char *);
	i = 0;

	 len = ft_strlen(s);
	if(flags.dot)
		len = (len > flags.max) ? flags.max : len;
	(flags.dash) ? ft_putnstr(s, len) : 0;
	ft_putnchar((flags.zero) ? '0' : ' ', flags.min - len);
	(!flags.dash) ? ft_putnstr(s, len) : 0;
	if (flags.min > len)
		return (flags.min);
	return (len);
}

int		ft_print_p_c(va_list args, t_flags flags)
{
	(void)args;
	(void)flags;
	write(1, "%", 1);
	return (1);
}

int		ft_print_c(va_list args, t_flags flags)
{
	int c;

	(void)flags;
	c = va_arg(args, int);
	write(1, &c, 1);
	return (1);
}

int	get_space(t_flags flags, int new_len, int nb)
{
	int space;

	space = 0;
	(nb <  0) ? new_len++ : 0;
	if (flags.min > new_len)
		space = flags.min - new_len;
	return (space);
}

int	get_dot_zero(t_flags flags, int *len, int nb)
{
	int zero;

	zero = 0;
	if (flags.max == 0 && nb == 0)
	{
		*len = 0;
		return (0);
	}
	if (flags.max < 0) //ptet gerer ça dans init flags
		zero = 0;
	if (flags.max > *len)
		zero = flags.max - *len;
	return(zero);
}

int		ft_print_d(va_list args, t_flags flags)
{
	int nb;
	int len;
	int zero;
	int space;

	nb = va_arg(args, int);
	len = ft_int_len(nb);
	zero = (flags.dot) ? get_dot_zero(flags, &len, nb) : 0;
	space = get_space(flags, len + zero, nb);
	ft_putnchar(' ', flags.zero ? 0 : space);
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
		len++;
	}
	ft_putnchar('0', flags.zero ? space : zero);
	len > 0 ? ft_putnbr(nb) : 0;
	return (len + zero + space);
}

int		ft_print_u(va_list args, t_flags flags)
{
	unsigned int n;

	(void)flags;
	n = va_arg(args, unsigned int);
	ft_putnbr_u(n);
	return (ft_u_len(n));
}

int		ft_print_p(va_list args, t_flags flags)
{
	long n;

	(void)flags;
	n = va_arg(args, long);
	ft_putstr("0x");
	ft_putnbr_base(n, "0123456789abcdef");
	return (ft_len_base(n, 16) + 2);
}

int		ft_print_x(va_list args, t_flags flags)
{
	long l;

	(void)flags;
	l = va_arg(args, long);
	ft_putnbr_base(l, "0123456789abcdef");
	return (ft_len_base(l, 16));
}

int		ft_print_x_2(va_list args, t_flags flags)
{
	long l;

	(void)flags;
	l = va_arg(args, long);
	ft_putnbr_base(l, "0123456789ABCDEF");
	return (ft_len_base(l, 16));
}

/*
 ** c s p d i u x X %
 */

int		init_functions(int (*functions[]) (va_list, t_flags))
{
	functions[0] = ft_print_c;
	functions[1] = ft_print_s;
	functions[2] = ft_print_p;
	functions[3] = ft_print_d;
	functions[4] = ft_print_d;
	functions[5] = ft_print_u;
	functions[6] = ft_print_x;
	functions[7] = ft_print_x_2;
	functions[8] = ft_print_p_c;
	return (0);
}

int		ft_printf(const char *string, ...)
{
	va_list	args;
	int		i;
	int		len;
	char	*s;

	i = 0;
	len = 0;
	va_start(args, string);
	s = ft_strndup(string, ft_strlen(string));
	while (s[i])
	{
		if (s[i] == '%')
			len += parse(&s[i + 1], args);
		else
			(++len) ? ft_putchar(s[i]) : 0;
		i++;
	}
	va_end(args);
	free(s);
	return (len);
}
