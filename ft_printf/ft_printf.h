/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgouacid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 15:57:54 by kgouacid          #+#    #+#             */
/*   Updated: 2020/01/03 15:40:42 by kgouacid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>  //ofc remove this
# include <string.h>  //ofc remove this
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

# define TYPE_FIELD "cspdiuxX%"
# define FLAGS "0-*."

typedef struct s_flags
{
	int dot;
	int dash;
	int zero;
	int min;
	int max;
}		t_flags;

int		ft_printf(const char *string, ...);
int		ft_strlen(const char *s);
#endif
