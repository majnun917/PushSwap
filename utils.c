/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndieye <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 02:20:56 by ndieye            #+#    #+#             */
/*   Updated: 2023/05/26 02:41:37 by ndieye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str && str[i] != '\0')
		i++;
	return (i);
}

static int	ft_nword(char const *s, char c)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (s != NULL && *s != '\0')
	{
		if (*s == c)
			i = 0;
		else if (*s != c && i == 0)
		{
			i = 1;
			n++;
		}
		s++;
	}
	return (n);
}

static char	*ft_word(const char *s, int start, int end)
{
	char	*word;
	int		i;
	int		len;

	i = 0;
	len = end - start;
	word = malloc(sizeof(char) * (len + 1));
	while (start < end)
	{
		word[i] = s[start];
		i++;
		start++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	int		k;
	char	**spl;

	spl = malloc(sizeof(char *) * (ft_nword(s, c) + 1));
	if (!s || !spl)
		return (0);
	i = 0;
	j = 0;
	k = -1;
	while (i <= ft_strlen(s))
	{
		if ((s[i] == c || i == ft_strlen(s)) && k >= 0)
		{
			spl[j] = ft_word(s, k, i);
			j++;
			k = -1;
		}
		else if (s[i] != c && k < 0)
			k = i;
		i++;
	}
	spl[j] = 0;
	return (spl);
}
