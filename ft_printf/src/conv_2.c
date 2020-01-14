/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgouacid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 14:40:01 by kgouacid          #+#    #+#             */
/*   Updated: 2020/01/14 14:25:59 by kgouacid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_print_p(va_list args, t_flags flags)
{
	long n;
	long len;
	long space;

	n = va_arg(args, long);
	len = ft_len_base(n, 16) + 2;
	space = (flags.min > len) ? flags.min - len : 0;
	(flags.dash) ? 0 : ft_putnchar(' ', space);
	ft_putstr("0x");
	ft_putnbr_base(n, "0123456789abcdef");
	(flags.dash) ? ft_putnchar(' ', space) : 0;
	return ((int)(len + space));
}

int		ft_u_to_hex(unsigned int n, char *base, t_flags flags)
{
	int				len;
	int				space;
	int				zero;
	char			c;

	zero = 0;
	c = flags.zero ? '0' : ' ';
	len = (!n && flags.max == 0 && flags.dot) ?
		0 : ft_len_base(n, ft_strlen(base));
	if (flags.dot)
		zero = flags.max > len ? flags.max - len : 0;
	space = flags.min > len + zero ? flags.min - (len + zero) : 0;
	(flags.dash) ? 0 : ft_putnchar(c, space);
	ft_putnchar('0', zero);
	(len > 0) ? ft_putnbr_base(n, base) : 0;
	(flags.dash) ? ft_putnchar(c, space) : 0;
	return (len + space + zero);
}

int		ft_print_x(va_list args, t_flags flags)
{
	long l;

	l = va_arg(args, unsigned int);
	return (ft_u_to_hex(l, "0123456789abcdef", flags));
}

int		ft_print_x_2(va_list args, t_flags flags)
{
	long l;

	(void)flags;
	l = va_arg(args, unsigned int);
	return (ft_u_to_hex(l, "0123456789ABCDEF", flags));
}
