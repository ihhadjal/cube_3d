/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilhasnao <ilhasnao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 08:28:05 by ilhasnao          #+#    #+#             */
/*   Updated: 2024/11/18 10:50:18 by ilhasnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*tab;
	size_t	s_len;
	size_t	j;

	s_len = 0;
	j = 0;
	if (!s)
		return (NULL);
	while (s[s_len] != '\0')
		s_len++;
	while (start <= s_len && s[start + j] != '\0' && j < len)
		j++;
	tab = (char *)malloc((j + 1) * sizeof(char));
	if (!tab)
		return (NULL);
	j = 0;
	while (start <= s_len && s[start + j] != '\0' && j < len)
	{
		tab[j] = s[start + j];
		j++;
	}
	tab[j] = '\0';
	return (tab);
}
// char	*ft_substr(char const *s, unsigned int start, size_t len)
// {
// 	char			*tab;
// 	size_t	s_len;
// 	size_t			i;

// 	s_len = ft_strlen(s);
// 	if (!s)
// 		return (NULL);
// 	if (start >= s_len)
// 	{
// 		return (NULL);
// 	}
// 	if (len + start > s_len)
// 	{
// 		len = s_len - start;
// 	}
// 	tab = malloc((sizeof(char) * len) + 1);
// 	if (!tab)
// 		return (NULL);
// 	i = 0;
// 	while (i < len && start < s_len)
// 	{
// 		tab[i] = s[start];
// 		start++;
// 		i++;
// 	}
// 	tab[i] = '\0';
// 	return (tab);
// }

// #include <stdio.h>
// int	main(void)
// {
// 	char const	b[] = "poooooop";
// 	unsigned int	begin = 3;
// 	size_t		taille = 6;

// 	printf("%s", ft_substr(b, begin, taille));
// 	return (0);
// }
