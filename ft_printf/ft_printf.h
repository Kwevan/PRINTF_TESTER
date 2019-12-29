/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgouacid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 15:57:54 by kgouacid          #+#    #+#             */
/*   Updated: 2019/12/19 12:52:45 by kgouacid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>  //ofc remove this
# include <string.h>  //ofc remove this
# include <stdarg.h>
# include <unistd.h>

# define TYPE_FIELD "cspdiuxX%"

int	ft_printf(const char *string, ...);

#endif
