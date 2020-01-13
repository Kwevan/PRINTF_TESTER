/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgouacid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 14:40:31 by kgouacid          #+#    #+#             */
/*   Updated: 2020/01/13 15:19:17 by kgouacid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		get_space(t_flags flags, int new_len, int nb)
{
	int space;

	space = 0;
	(nb < 0) ? new_len++ : 0;
	if (flags.min > new_len)
		space = flags.min - new_len;
	return (space);
}

int		get_dot_zero(t_flags flags, int *len, int nb)
{
	int zero;

	zero = 0;
	if (flags.max == 0 && nb == 0)
	{
		*len = 0;
		return (0);
	}
	if (flags.max > *len)
		zero = flags.max - *len;
	return (zero);
}

int		ft_print_d(va_list args, t_flags flags)
{
	long	nb;
	int		len;
	int		zero;
	int		space;

	nb = (long)va_arg(args, int);
	len = ft_int_len(nb);
	zero = (flags.dot) ? get_dot_zero(flags, &len, nb) : 0;
	space = get_space(flags, len + zero, nb);
	ft_putnchar(' ', (flags.zero || flags.dash) ? 0 : space);
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
		len++;
	}
	ft_putnchar('0', (flags.zero) ? space : zero);
	len > 0 ? ft_putnbr(nb) : 0;
	ft_putnchar(' ', (flags.dash) ? space : 0);
	return (len + zero + space);
}
