/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwinston <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 12:35:22 by hwinston          #+#    #+#             */
/*   Updated: 2019/10/25 16:59:49 by hwinston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static void		free_str(char **str)
{
	if (*str)
	{
		free(*str);
		*str = NULL;
	}
}

static void		free_stock(char **stock)
{
	int i;

	i = -1;
	while (stock[++i])
	{
		free(stock[i]);
		stock[i] = NULL;
	}
	free(*stock);
	*stock = NULL;
}

static int		set_line(char **stock, char **line)
{
	int		i;
	char	*tmp;

	if (!(tmp = ft_strdup(*stock)))
		return (-1);
	i = 0;
	while (tmp[i] != '\n' && tmp[i])
		i++;
	if (!(*line = ft_strndup(*stock, i)))
	{
		free_str(&tmp);
		return (-1);
	}
	if (*stock)
		free_str(stock);
	if (tmp[i] != '\0')
		if (!(*stock = ft_strdup(&(tmp)[i + 1])))
		{
			free_str(&tmp);
			return (-1);
		}
	free_str(&tmp);
	return (i);
}

static int		read_file(int fd, char **stock)
{
	char	buf[BUFFER_SIZE + 1];
	char	*tmp;
	int		ret;

	while ((ret = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[ret] = '\0';
		tmp = ft_strdup(*stock);
		free_str(stock);
		if (!(*stock = ft_strjoin(tmp, buf)))
		{
			free_str(&tmp);
			return (-1);
		}
		free_str(&tmp);
		if (ft_strchr(*stock, '\n'))
			break ;
	}
	return (ret);
}

int				get_next_line(int fd, char **line)
{
	static char		*stock[MAX_FD];

	if (fd < 0 || fd > MAX_FD || !line || BUFFER_SIZE < 1)
		return (-1);
	if (!stock[fd])
		if (!(stock[fd] = ft_strdup("")))
		{
			free_stock(stock);
			return (-1);
		}
	if (!(ft_strchr(stock[fd], '\n')))
		if ((read_file(fd, &stock[fd])) == -1)
		{
			free_stock(stock);
			return (-1);
		}
	if (set_line(&stock[fd], line) == -1)
	{
		free_str(stock);
		return (-1);
	}
	if (!stock[fd])
		return (0);
	return (1);
}
