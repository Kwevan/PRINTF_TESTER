#include "ft_printf.h"

int		ft_print_s(va_list args, t_flags flags)
{
	char	*s;
	int		i;
	int len;
	s = va_arg(args, char *);
	i = 0;

	 len = ft_strlen(s);
	if(flags.dot)
		len = (len > flags.max) ? flags.max : len;
	(flags.dash) ? ft_putnstr(s, len) : 0;
	ft_putnchar((flags.zero) ? '0' : ' ', flags.min - len);
	(!flags.dash) ? ft_putnstr(s, len) : 0;
	if (flags.min > len)
		return (flags.min);
	return (len);
}

