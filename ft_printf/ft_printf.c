/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgouacid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 15:58:03 by kgouacid          #+#    #+#             */
/*   Updated: 2020/01/10 17:23:33 by kgouacid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_print_s(va_list args, t_flags flags)
{
	char	*s;
	int		i;
	s = va_arg(args, char *);
	i = 0;

	int len = ft_strlen(s);

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

int	get_space(t_flags flags, int new_len)
{
	int space;

	space = 0;
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
	space = get_space(flags, len + zero);
	ft_putnchar(' ', space);
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
		len++;
	}
	ft_putnchar('0', zero);
	len > 0 ? ft_putnbr(nb) : 0;
	return (len + zero + space);
}


/*int		ft_print_d(va_list args, t_flags flags)
{

	int n;
	int len;
	int zero;
	char space;

	space = flags.zero ? '0' : ' ';
	zero = 0;
	n = va_arg(args, int);
	len = ft_int_len(n);
	if (flags.dot && flags.max > len)
		zero = flags.max - len;
*//*	if (n < 0)
		{
		ft_putchar('-');
		n *= -1;
}*/
/*	if (flags.dot)
	{
		if (flags.min > len + zero)
			ft_putnchar(space, flags.min - (zero + len));
	}
	else
	{
		if (flags.min > len)
			ft_putnchar(space, flags.min - len);
	}
	if(!n && flags.dot && (flags.min == 0 && flags.max == 0))
	{		
		return (0);
	}
	ft_putnchar('0', zero);

	if(!n && flags.dot && flags.max == 0)
		ft_putchar(' ');
	else
	ft_putnbr(n);

	if(flags.dot && flags.max > len)
	{
		if(flags.min >  len + zero)
			return (len + zero);
	//		return (flags.min - (len + zero) + len + zero);
	}
	else if(flags.min > len)
		return (flags.min);
	return (len);
}
*/
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

int		ft_print_X(va_list args, t_flags flags)
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
	functions[7] = ft_print_X;
	functions[8] = ft_print_p_c;
	return (0);
}

void	ft_reset_flags(t_flags *flags)
{
	flags->dot = 0;
	flags->dash = 0;
	flags->zero = 0;
	flags->min = 0;
	flags->max = 0;
}

int	zero_flag(char *s)
{
	int i;

	i = 0;
	if (s[0] == '0')
		return (1);
	while(s[i])
	{
		if (s[i] == '0' && !(ft_index("0123456789.", s[i - 1]) + 1 ))
			return (1);
		i++;
	}
	return (0);
}
//comprends plus pk  j'ai du strndup dans parse avec le char de conversion ex je ndup "%2.2s"
//faudra recoder init_flags

void init_flags(va_list args, t_flags *flags, char *rest)
{
	int i;
	int nb;
	ft_reset_flags(flags);
	i = 0;
	nb = 0;

	while (rest[i])
	{
		if ((ft_index("0123456789", rest[i]) + 1) || (ft_index("*", rest[i]) + 1))
		{
			if (rest[i] == '*')
				nb = va_arg(args, int);
			else
				nb = nb * 10 + rest[i] - '0';
			if (nb < 0)
			{

				//		ft_reset_flags(flags);
				flags->dot = 0;
				flags->min = -nb; //pas sur
				flags->dash = 1; //pas sur
				return ;
			}
		}
		else
		{
			if (ft_nindex(rest, '.', i) + 1) //le flags.dot pe etre gere ici
				flags->max = nb;
			else
			{
				flags->min = nb;
				nb = 0;
			}
		}
		i++;
	}
	flags->dot = ft_index(rest, '.') + 1 ? 1 : 0; 
	flags->dash = ft_index(rest, '-') + 1 ? 1 : 0; 
	flags->zero = zero_flag(rest);
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
