/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamehri <tamehri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 18:17:28 by tamehri           #+#    #+#             */
/*   Updated: 2024/01/07 16:53:31 by tamehri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (*(str + i))
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*res;

	i = ft_strlen(s1);
	res = malloc((i + 1) * sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	while (*(s1 + i))
	{
		*(res + i) = *(s1 + i);
		i++;
	}
	*(res + i) = '\0';
	return (res);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*res;

	res = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!res)
		return (NULL);
	i = -1;
	while (*(s1 + ++i))
		*(res + i) = *(s1 + i);
	j = 0;
	while (*(s2 + j))
		*(res + i++) = *(s2 + j++);
	*(res + i) = '\0';
	return (res);
}

char	*get_next_line(int fd)
{
	char	*line;
	int		ret;

	line = malloc(5 * sizeof(char));
	if (!line)
		return (NULL);
	ret = read(fd, line, 5);
	line[ret] = '\0';
	if (ret == -1)
		return (NULL);
	return (line);
}
