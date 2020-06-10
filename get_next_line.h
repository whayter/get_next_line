/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwinston <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 14:16:56 by hwinston          #+#    #+#             */
/*   Updated: 2019/10/25 17:00:13 by hwinston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFFER_SIZE 100

# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>

int		get_next_line(int fd, char **line);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(char const *s);
char	*ft_strdup(char const *s1);
char	*ft_strndup(char const *s1, int n);
char	*ft_strjoin(char const *s1, char const *s2);

#endif
