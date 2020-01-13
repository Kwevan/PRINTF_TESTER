/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgouacid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 14:39:33 by kgouacid          #+#    #+#             */
/*   Updated: 2020/01/13 16:03:37 by kgouacid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_print_p_c(va_list args, t_flags flags)
{
	int len;
	(void)args;
	char c;

	c = (flags.zero) ? '0' : ' ' ;
	len = (flags.min) ? flags.min : 1;
	(flags.dash) ? 0 :ft_putnchar(c, len - 1);
	ft_putchar('%');
	(flags.dash) ?  ft_putnchar(c, len - 1) : 0;
	return (len);
}

int		ft_print_c(va_list args, t_flags flags)
{
	int c;
	int len;

	c = va_arg(args, int);

	len =  (flags.min == 0) ? 1 : flags.min;
	(flags.dash) ? 0 :ft_putnchar(' ', len - 1);
	ft_putchar(c);
	(flags.dash) ? ft_putnchar(' ', len - 1) : 0;
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
