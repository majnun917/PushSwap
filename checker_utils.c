/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndieye <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 23:39:28 by ndieye            #+#    #+#             */
/*   Updated: 2023/05/24 01:18:43 by ndieye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strcmp(const char *str1, const char *str2)
{
	size_t	i;

	i = 0;
	while ((str1[i] != '\0' || str2[i] != '\0'))
	{
		if ((unsigned char)str1[i] > (unsigned char)str2[i])
			return (1);
		if ((unsigned char)str1[i] < (unsigned char)str2[i])
			return (-1);
		i++;
	}
	return (0);
}

char	*ft_strdup(const char *src)
{
	size_t	len;
	char	*dest;

	len = ft_strlen(src) + 1;
	dest = malloc(len);
	if (dest != NULL)
		ft_strlcpy(dest, src, len);
	return (dest);
}

char	*ft_strchr(const char *str, int c)
{
	while (*str != (char)c && *str != '\0')
		str++;
	if (*str == (char)c)
		return ((char *)str);
	else
		return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	len;
	int		i;
	int		j;

	len = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	j = -1;
	while (s2[++j])
		str[i++] = s2[j];
	str[i] = '\0';
	free ((char *)s1);
	return (str);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t destsize)
{
	size_t	i;
	size_t	len;

	len = ft_strlen(src);
	if (destsize != 0)
	{
		i = 0;
		while (src[i] && i < destsize - 1)
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (len);
}
