/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgouacid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 12:46:54 by kgouacid          #+#    #+#             */
/*   Updated: 2020/01/14 13:46:39 by kgouacid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int				ft_int_len(int n)
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

unsigned int	ft_u_len(unsigned int n)
{
	unsigned int len;

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

int				ft_len_base(long l, int base)
{
	int len;

	len = 0;
	while (l >= base)
	{
		l = l / base;
		len++;
	}
	len++;
	return (len);
}
