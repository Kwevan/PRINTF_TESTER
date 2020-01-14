/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgouacid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 14:39:33 by kgouacid          #+#    #+#             */
/*   Updated: 2020/01/14 13:46:24 by kgouacid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_print_p_c(va_list args, t_flags flags)
{
	int		len;
	char	c;

	(void)args;
	c = (flags.zero) ? '0' : ' ';
	len = (flags.min) ? flags.min : 1;
	(flags.dash) ? 0 : ft_putnchar(c, len - 1);
	ft_putchar('%');
	(flags.dash) ? ft_putnchar(c, len - 1) : 0;
	return (len);
}

int		ft_print_c(va_list args, t_flags flags)
{
	int c;
	int len;

	c = va_arg(args, int);
	len = (flags.min == 0) ? 1 : flags.min;
	(flags.dash) ? 0 : ft_putnchar(' ', len - 1);
	ft_putchar(c);
	(flags.dash) ? ft_putnchar(' ', len - 1) : 0;
	return (len);
}

int		ft_print_u(va_list args, t_flags flags)
{
	unsigned int	n;
	int				len;
	int				space;
	int				zero;
	char			c;

	zero = 0;
	c = flags.zero ? '0' : ' ';
	n = va_arg(args, unsigned int);
	len = (!n && flags.max == 0 && flags.dot) ? 0 : (int)ft_u_len(n);
	if (flags.dot)
		zero = flags.max > len ? flags.max - len : 0;
	space = flags.min > len + zero ? flags.min - (len + zero) : 0;
	(flags.dash) ? 0 : ft_putnchar(c, space);
	ft_putnchar('0', zero);
	(len > 0) ? ft_putnbr_u(n) : 0;
	(flags.dash) ? ft_putnchar(c, space) : 0;
	return (len + space + zero);
}
