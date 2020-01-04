/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgouacid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 15:58:03 by kgouacid          #+#    #+#             */
/*   Updated: 2020/01/03 15:39:39 by kgouacid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
 ** pas compris si je peux nommer mon .h principal comme je veux
 ** return nimp si on passe un unsigned int comme printf
 */

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnchar(char c, int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		write(1, &c, 1);
		i++;	
	}
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

void	ft_putnstr(char *str, int n)
{
	int i;

	i = 0;
	while (str[i] && i < n)
	{
		ft_putchar(str[i]);
		i++;
	}

}

int		ft_int_len(int n)
{
	int len;

	len = (n < 0) ? 1 : 0;
	if (!n)
		return (1);
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

int		ft_u_len(unsigned int n)
{
	int len;

	len = 0;
	if (!n)
		return (1);
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

int		ft_putnbr(int n)
{
	char c;

	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	if (n > 9)
		ft_putnbr(n / 10);
	c = '0' + n % 10;
	write(1, &c, 1);
	return (1);
}

int		ft_putnbr_u(unsigned int n)
{
	char c;

	if (n > 9)
		ft_putnbr_u(n / 10);
	c = '0' + n % 10;
	ft_putchar(c);
	return (1);
}

int		ft_putnbr_base(long n, char *base)
{
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	if (n > 15)
		ft_putnbr_base(n / 16, base);
	ft_putchar(base[n % 16]);
	return (1);
}

int		ft_len_base(long l, int base)
{
	int len;

	len = 0;
	while (l > base - 1)
	{
		l = l / base;
		len++;
	}
	len++;
	return (len);
}

int		ft_print_s(va_list args, t_flags flags)
{
	char	*s;
	int		i;
	s = va_arg(args, char *);
	i = 0;

	int len = strlen(s);

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

int		ft_print_d(va_list args, t_flags flags)
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

if (flags.dot)
{
	if (flags.min > len + zero)
		ft_putnchar(space, flags.min - (zero + len));
}
else
{
	if (flags.min > len)
		ft_putnchar(space, flags.min - len);
}
	if(!n && flags.dot)
		return (0);
	ft_putnchar('0', zero);
	
	ft_putnbr(n);

	if(flags.dot && flags.max > len )
	{
		if(flags.min >  len + zero)
				return (len + zero);
	}	
	else if(flags.min > len)
		return (flags.min);
	
		return (len);
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

void	ft_move(char *s1, char *s2)
{
	int i;

	i = 0;
	if (!s1 || !s2)
		return ;
	while (s2[i])
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = '\0';
}

int		ft_index(char *haystack, char needle)
{
	int i;

	i = 0;
	while (haystack[i])
	{
		if (haystack[i] == needle)
			return (i);
		i++;
	}
	return (-1);
}

int		ft_nindex(char *haystack, char needle, int n)
{
	int i;

	i = 0;
	while (haystack[i] && i < n)
	{
		if (haystack[i] == needle)
			return (i);
		i++;
	}
	return (-1);
}

void	ft_reset_flags(t_flags *flags)
{
	flags->dot = 0;
	flags->dash = 0;
	flags->zero = 0;
	flags->min = 0;
	flags->max = 0;
}

int	zero_flag(char *s, int n)
{
	int i;

	i = 0;
	if (s[0] == '0')
		return (1);
	while(s[i] && i < n)
	{
		if (s[i] == '0' && !(ft_index("0123456789.", s[i - 1]) + 1 ))
			return (1);
		i++;
	}
	return (0);
}

void init_flags(va_list args, t_flags *flags, int f_len, char *rest)
{
	int i;
	int nb;
	ft_reset_flags(flags);
	i = 0;
	nb = 0;
	while (rest[i] && i < f_len + 1)
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
	flags->zero = zero_flag(rest, f_len);
}

int		parse(char *rest, va_list args)
{
	int len;
	int pos;
	int f_len;
	t_flags flags;
	int		(*functions[9])(va_list, t_flags);


	f_len = 0;
	init_functions(functions);
	len = 0;
	while (rest[f_len] && !(ft_index(TYPE_FIELD, rest[f_len]) + 1))
		f_len++;
	init_flags(args, &flags, f_len, rest);
	if ((pos = ft_index(TYPE_FIELD, rest[f_len])) + 1 )
	{
		len += functions[pos](args, flags);
		ft_move(rest, rest + f_len + 1);
	}
	else
		len += functions[8](args, flags);
	return (len);
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
	s = strdup(string);
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
