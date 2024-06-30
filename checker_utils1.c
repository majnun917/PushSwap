/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndieye <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 23:45:17 by ndieye            #+#    #+#             */
/*   Updated: 2023/05/24 01:01:23 by ndieye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*read_file(int fd, char *str)
{
	char	*buf;
	int		p_read;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	p_read = 1;
	if (!str)
	{
		str = ft_strdup("");
		if (!str)
			return (free(buf), NULL);
	}
	while (p_read > 0 && !ft_strchr(str, '\n'))
	{
		p_read = read(fd, buf, BUFFER_SIZE);
		if (p_read < 0)
			return (free(buf), free(str), NULL);
		buf[p_read] = '\0';
		str = ft_strjoin(str, buf);
		if (!str)
			return (free(buf), NULL);
	}
	return (free(buf), str);
}

static char	*get_line(char *str)
{
	char	*line;
	size_t	len;

	len = 0;
	if (!*str)
		return (NULL);
	while (str[len] && str[len] != '\n')
		len++;
	line = (char *)malloc(sizeof(char) * (len + 2));
	if (!line)
		return (NULL);
	ft_strlcpy(line, str, (len + 2));
	if (str[len] == '\n')
	{
		line[len] = '\n';
		len++;
	}
	return (line);
}

static char	*clean_read_line(char *str)
{
	int		len;
	int		i;
	char	*nstr;

	if (!str)
		return (NULL);
	if (!ft_strchr(str, '\n'))
		return (free(str), NULL);
	len = 0;
	while (str[len] && str[len] != '\n')
		len++;
	nstr = malloc(sizeof(char) * ((ft_strlen(str) - len) + 1));
	if (!nstr)
		return (free(str), NULL);
	len++;
	i = 0;
	while (str[len])
		nstr[i++] = str[len++];
	return (nstr[i] = '\0', free(str), nstr);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = read_file(fd, str);
	if (!str)
		return (NULL);
	line = get_line(str);
	str = clean_read_line(str);
	return (line);
}
