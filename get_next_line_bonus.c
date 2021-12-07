/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouhadou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 10:57:04 by aouhadou          #+#    #+#             */
/*   Updated: 2021/11/29 16:34:08 by aouhadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_line(char *buff)
{
	char	*res;
	int		count;

	count = 0;
	if (!buff)
		return (NULL);
	while (buff[count] != '\n' && buff[count])
		count++;
	count += 1;
	res = (char *)malloc(sizeof(char) * count + 1);
	if (!res)
		return (NULL);
	ft_memmove(res, buff, count);
	res[count] = '\0';
	return (res);
}

char	*get_reminder(char *str)
{
	char	*rem;
	int		count;
	int		len;

	count = 0;
	len = ft_strlen(str);
	if (!str)
		return (NULL);
	while (str[count] != '\n' && str[count])
		count++;
	if (!str[count])
	{
		free (str);
		return (0);
	}
	rem = (char *)malloc(sizeof(char) * (len - count));
	if (!rem)
		return (NULL);
	count += 1;
	ft_memmove(rem, str + count, (len - count));
	rem[len - count] = '\0';
	free (str);
	if (ft_strlen(rem) == 0)
		return (free(rem), NULL);
	return (rem);
}

int	ft_check(char *buff)
{
	int	i;

	if (!buff)
		return (0);
	i = 0;
	while (buff[i] != '\0')
	{
		if (buff[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*get_next_line(int fd)
{
	char			buff[BUFFER_SIZE + 1];
	int				re;
	char			*res;
	static char		*rem[1024];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	re = 1;
	while (re != 0 && !ft_check(rem[fd]))
	{
		re = read(fd, buff, BUFFER_SIZE);
		if (re == -1)
			return (NULL);
		if (re == 0)
		{
			buff[re] = '\0';
			break ;
		}
		buff[re] = '\0';
		rem[fd] = ft_strjoin(rem[fd], buff);
	}
	res = get_line(rem[fd]);
	rem[fd] = get_reminder(rem[fd]);
	return (res);
}
