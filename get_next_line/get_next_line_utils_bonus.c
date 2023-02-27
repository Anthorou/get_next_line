/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroussea <aroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 17:42:40 by aroussea          #+#    #+#             */
/*   Updated: 2023/02/24 11:48:10 by aroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strchr(const char *str, int nbr)
{
	int	i;
	int	len;

	if (!str)
		return (NULL);
	i = -1;
	len = ft_strlen(str);
	while (++i < len + 1)
		if (str[i] == (char)nbr)
			return ((char *)str + i);
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	int		i;
	int		x;

	if (!s1)
		s1 = ft_strdup("\0");
	new = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!new)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		new[i] = s1[i];
		i++;
	}
	x = 0;
	while (s2[x] != '\0')
	{
		new[i + x] = s2[x];
		x++;
	}
	new[i + x] = '\0';
	free((void *) s1);
	return (new);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned int	i;
	unsigned char	*ptr;

	i = 0;
	ptr = b;
	if (!b)
		return (b);
	while (i < len)
	{
		*ptr = c;
		ptr++;
		i++;
	}
	return (b);
}

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*rep;
	char	*check;

	i = 0;
	if (!s1)
		return ((char *)s1);
	while (s1[i] != '\0')
		i++;
	check = ((rep = (char *)malloc(1 * (i + 1))));
	if (!check)
		return (0);
	i = 0;
	while (s1[i] != '\0')
	{
		rep[i] = s1[i];
		i++;
	}
	rep[i] = '\0';
	return (rep);
}
