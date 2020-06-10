/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwinston <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 12:35:14 by hwinston          #+#    #+#             */
/*   Updated: 2019/10/25 14:38:44 by hwinston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	size_t i;

	i = -1;
	while (s[++i])
		if (s[i] == (char)c)
			return (&((char *)s)[i]);
	if (c == '\0')
		return (&((char *)s)[i]);
	return (NULL);
}

size_t	ft_strlen(char const *s)
{
	size_t i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(char const *s1)
{
	int		i;
	char	*s2;

	if (!(s2 = (char *)malloc(sizeof(char) * ft_strlen(s1) + 1)))
		return (NULL);
	i = 0;
	while (s1[i])
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

char	*ft_strndup(char const *s1, int n)
{
	int		i;
	char	*s2;

	if (!(s2 = (char *)malloc(sizeof(char) * n + 1)))
		return (NULL);
	i = 0;
	while (s1[i] && i < n)
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	int		size;
	char	*new_s;

	if (!s1 || !s2)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2);
	if (!(new_s = (char *)malloc(sizeof(char) * size + 1)))
		return (NULL);
	i = -1;
	while (s1[++i])
		new_s[i] = s1[i];
	j = -1;
	while (s2[++j])
	{
		new_s[i] = s2[j];
		i++;
	}
	new_s[i] = '\0';
	return (new_s);
}
