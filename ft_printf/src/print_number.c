/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgouacid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 12:38:15 by kgouacid          #+#    #+#             */
/*   Updated: 2020/01/10 13:28:47 by kgouacid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "ft_printf.h"

int		ft_putnbr(int n)
{
	char c;

	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	if (n > 9)
		ft_putnbr(n / 10);
	c = '0' + n % 10;
	ft_putchar(c);
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
	int base_len;

	base_len = ft_strlen(base);
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	if (n >= base_len)
		ft_putnbr_base(n / base_len, base);
	ft_putchar(base[n % base_len]);
	return (1);
}
