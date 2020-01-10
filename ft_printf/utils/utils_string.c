/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgouacid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 11:16:25 by kgouacid          #+#    #+#             */
/*   Updated: 2020/01/10 12:13:20 by kgouacid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_move(char *s1, char *s2)
{
	int i;

	i = 0;
	if (!s1 || !s2)
		return ;
	while (s2[i])
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = '\0';
}

int		ft_strlen(const char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int		ft_nindex(char *haystack, char needle, int n)
{
	int i;

	i = 0;
	while (haystack[i] && i < n)
	{
		if (haystack[i] == needle)
			return (i);
		i++;
	}
	return (-1);
}

int		ft_index(char *haystack, char needle)
{
	int i;

	i = 0;
	while (haystack[i])
	{
		if (haystack[i] == needle)
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_strndup(const char *s, int n)
{
	int		i;
	int		len;
	char	*dest;

	if (!s)
		return (NULL);
	i = 0;
	len = ft_strlen(s);
	(n > len) ? n = len : 0;
	dest = (char *)malloc(sizeof(char) * (n + 1));
	if (!dest)
		return (NULL);
	while (s[i] && i < n)
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
