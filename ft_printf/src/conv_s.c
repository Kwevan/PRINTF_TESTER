/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgouacid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 14:40:13 by kgouacid          #+#    #+#             */
/*   Updated: 2020/01/13 15:03:31 by kgouacid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_print_s(va_list args, t_flags flags)
{
	char	*s;
	int		len;

	s = va_arg(args, char *);
	if (!s)
	{
		ft_putstr("(null)");
		return (ft_strlen("(null)"));
	}
	len = ft_strlen(s);
	if (flags.dot)
		len = (len > flags.max) ? flags.max : len;
	(flags.dash) ? ft_putnstr(s, len) : 0;
	ft_putnchar((flags.zero) ? '0' : ' ', flags.min - len);
	(!flags.dash) ? ft_putnstr(s, len) : 0;
	if (flags.min > len)
		return (flags.min);
	return (len);
}
