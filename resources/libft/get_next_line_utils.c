/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihhadjal <ihhadjal@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:31:40 by ihhadjal          #+#    #+#             */
/*   Updated: 2025/06/29 17:12:50 by ihhadjal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_sstrchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)s + i);
	return (NULL);
}

char	*ft_sstrdup(const char *s)
{
	char	*dup;
	size_t	i;

	i = 0;
	dup = (char *)malloc(sizeof(char) * (ft_sstrlen(s) + 1));
	if (!dup)
		return (NULL);
	while (s[i])
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = 0;
	return (dup);
}

size_t	ft_sstrlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_sstrjoin(char *s1, char *s2)
{
	int		i;
	int		c;
	char	*result;

	i = 0;
	c = 0;
	if (!s1 || !s2)
		return (NULL);
	result = malloc(sizeof(char) * ft_sstrlen(s1) + ft_sstrlen(s2) + 1);
	if (!result)
		return (NULL);
	while (s1[i])
	{
		result[i] = s1[i];
		i++;
	}
	while (s2[c])
	{
		result[i] = s2[c];
		i++;
		c++;
	}
	result[i] = '\0';
	return (result);
}
