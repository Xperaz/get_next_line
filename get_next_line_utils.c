/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouhadou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 10:54:52 by aouhadou          #+#    #+#             */
/*   Updated: 2021/11/29 16:42:29 by aouhadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*dest;
	char	*src1;
	size_t	i;

	i = 0;
	dest = (char *)dst;
	src1 = (char *)src;
	if (!dest || !src)
		return (NULL);
	dest[len] = '\0';
	if (src1 > dest)
	{
		while (len > i)
		{
			dest[i] = src1[i];
			i++;
		}
	}
	else
	{
		while (len--)
			dest[len] = src1[len];
	}
	return (dest);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	unsigned int	len;
	char			*res;

	len = ft_strlen(s1) + ft_strlen(s2);
	res = (char *) malloc(sizeof(char) * len + 1);
	if (!res)
		return (NULL);
	ft_memmove(res, s1, ft_strlen(s1));
	ft_memmove(res + ft_strlen(s1), s2, ft_strlen(s2));
	res[len] = '\0';
	free((char *)s1);
	return (res);
}
