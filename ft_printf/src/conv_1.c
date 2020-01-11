#include "ft_printf.h"

int		ft_print_p_c(va_list args, t_flags flags)
{
	(void)args;
	(void)flags;
	write(1, "%", 1);
	return (1);
}

int		ft_print_c(va_list args, t_flags flags)
{
	int c;

	(void)flags;
	c = va_arg(args, int);
	write(1, &c, 1);
	return (1);
}

int		ft_print_u(va_list args, t_flags flags)
{
	unsigned int n;

	(void)flags;
	n = va_arg(args, unsigned int);
	ft_putnbr_u(n);
	return (ft_u_len(n));
}



