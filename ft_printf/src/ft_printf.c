/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgouacid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 15:58:03 by kgouacid          #+#    #+#             */
/*   Updated: 2020/01/14 14:31:43 by kgouacid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 ** c s p d i u x X %
*/

int		ft_init_functions(int (*functions[]) (va_list, t_flags))
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
			ft_parse(&s[i + 1], args, &len);
		else
			(++len) ? ft_putchar(s[i]) : 0;
		i++;
	}
	va_end(args);
	free(s);
	return (len);
}
