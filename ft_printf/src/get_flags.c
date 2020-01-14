/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgouacid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 12:29:55 by kgouacid          #+#    #+#             */
/*   Updated: 2020/01/14 14:34:40 by kgouacid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_reset_flags(t_flags *flags)
{
	flags->dot = 0;
	flags->dash = 0;
	flags->zero = 0;
	flags->min = 0;
	flags->max = 0;
}

int		ft_zero_flag(char *s)
{
	int i;

	i = 0;
	if (s[0] == '0')
		return (1);
	while (s[i])
	{
		if (s[i] == '0' && !(ft_index("0123456789.", s[i - 1]) + 1))
			return (1);
		i++;
	}
	return (0);
}

void	ft_init_flags_p1(t_flags *flags, char *s_flags)
{
	ft_reset_flags(flags);
	flags->dot = ft_index(s_flags, '.') + 1 ? 1 : 0;
	flags->dash = ft_index(s_flags, '-') + 1 ? 1 : 0;
	flags->zero = ft_zero_flag(s_flags);
}

void	ft_init_flags_p2(t_flags *flags, char *rest, int i, int *nb)
{
	if (!(ft_nindex(rest, '.', i) + 1))
	{
		flags->min = (*nb < 0) ? -(*nb) : *nb;
		(*nb < 0) ? flags->dash = 1 : 0;
		*nb = 0;
	}
	else
	{
		if (*nb < 0)
			flags->dot = 0;
		else
			flags->max = *nb;
	}
}

void	ft_init_flags(va_list args, t_flags *flags, char *rest, int not_ign_0)
{
	int i;
	int nb;

	ft_init_flags_p1(flags, rest);
	i = 0;
	nb = 0;
	while (rest[i])
	{
		if ((ft_index("0123456789", rest[i]) + 1)
				|| (ft_index("*", rest[i]) + 1))
		{
			if (rest[i] == '*')
				nb = va_arg(args, int);
			else
				nb = nb * 10 + rest[i] - '0';
		}
		else
			ft_init_flags_p2(flags, rest, i, &nb);
		i++;
	}
	if ((flags->dot && !not_ign_0) || flags->dash)
		flags->zero = 0;
}
