/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroussea <aroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 17:42:23 by aroussea          #+#    #+#             */
/*   Updated: 2023/02/24 11:51:16 by aroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_read(int fd, char *s)
{
	char	*s2;
	int		verif;

	verif = 1;
	s2 = (char *)malloc (sizeof(char) * BUFFER_SIZE + 1);
	if (!s2)
		return (NULL);
	while (!ft_strchr(s, '\n') && verif != 0)
	{
		ft_memset(s2, 0, BUFFER_SIZE);
		verif = read(fd, s2, BUFFER_SIZE);
		if (verif < 0)
		{
			free(s);
			free(s2);
			return (NULL);
		}
		s2[BUFFER_SIZE] = '\0';
		if (verif != 0)
			s = ft_strjoin(s, s2);
	}
	free(s2);
	return (s);
}

char	*check_line(char *start)
{
	char	*rep;
	int		i;

	if (!start || !start[0])
		return (NULL);
	i = 0;
	while (start[i] && start[i] != '\n')
		i++;
	i += (start[i] == '\n');
	rep = (char *)malloc(sizeof(char) * i + 1);
	if (!rep)
	{
		free(start);
		return (NULL);
	}
	i = 0;
	while (start[i] && start[i] != '\n')
	{
		rep[i] = start[i];
		i++;
	}
	if (start[i] == '\n')
		rep[i++] = '\n';
	rep[i] = '\0';
	return (rep);
}

char	*move_start(char *start)
{
	char	*new_start;
	int		i;
	int		j;

	if (!start || !start[0])
		return (NULL);
	i = 0;
	while (start[i] && start[i] != '\n')
		i++;
	i += (start[i] == '\n');
	new_start = (char *)malloc(sizeof(char) * (ft_strlen(start) - i + 1));
	if (!new_start)
	{
		free(start);
		return (NULL);
	}
	j = 0;
	while (start[i + j])
	{
		new_start[j] = start[i + j];
		j++;
	}
	new_start[j] = '\0';
	free(start);
	return (new_start);
}

char	*get_next_line(int fd)
{
	static char	*buf[OPEN_MAX];
	char		*rep;

	if (BUFFER_SIZE < 1 || fd < 0)
		return (NULL);
	buf[fd] = get_read(fd, buf[fd]);
	if (!buf[fd] || buf[fd][0] == '\0')
	{
		free(buf[fd]);
		return (NULL);
	}
	rep = check_line(buf[fd]);
	buf[fd] = move_start(buf[fd]);
	return (rep);
}
