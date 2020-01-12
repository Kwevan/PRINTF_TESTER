//#include "ft_printf.h"

int	get_space(t_flags flags, int new_len, int nb)
{
	int space;

	space = 0;
	(nb <  0) ? new_len++ : 0;
	if (flags.min > new_len)
		space = flags.min - new_len;
	return (space);
}

int	get_dot_zero(t_flags flags, int *len, int nb)
{
	int zero;

	zero = 0;
	if (flags.max == 0 && nb == 0)
	{
		*len = 0;
		return (0);
	}
	if (flags.max < 0) //ptet gerer ça dans init flags
		zero = 0;
	if (flags.max > *len)
		zero = flags.max - *len;
	return(zero);
}

int		ft_print_d(va_list args, t_flags flags)
{
	int nb;
	int len;
	int zero;
	int space;

	nb = va_arg(args, int);
	len = ft_int_len(nb);
	zero = (flags.dot) ? get_dot_zero(flags, &len, nb) : 0;
	space = get_space(flags, len + zero, nb);
	ft_putnchar(' ', flags.zero ? 0 : space);
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
		len++;
	}
	ft_putnchar('0', flags.zero ? space : zero);
	len > 0 ? ft_putnbr(nb) : 0;
	return (len + zero + space);
}


