/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasnawww <hasnawww@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 06:57:00 by ilhasnao          #+#    #+#             */
/*   Updated: 2025/02/05 15:30:51 by hasnawww         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

int	count_words(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		while (s[i] && s[i] == c)
		{
			i++;
		}
		if (s[i] && s[i] != c)
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (count);
}

static size_t	word_len(char const	*s, char c)
{
	int	j;

	j = 0;
	while (s[j] && s[j] != c)
		j++;
	return (j);
}

char	**ft_split(char const *s, char c)
{
	char		**result;
	size_t		len;
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	result = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!result || !s)
		return (NULL);
	while (s[i] != '\0')
	{
		while (s[i] != '\0' && s[i] == c)
			i++;
		len = word_len(&s[i], c);
		if (s[i] != '\0')
		{
			result[j] = ft_substr(s, i, len);
			j++;
			i = i + len;
		}
	}
	result[j] = NULL;
	return (result);
}
