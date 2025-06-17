/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilhasnao <ilhasnao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:00:32 by ilhasnao          #+#    #+#             */
/*   Updated: 2024/11/14 11:54:29 by ilhasnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

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

size_t	to_find(char const *s, char c)
{
	while (*s)
	{
		if (c == *s)
		{
			return (1);
		}
		s++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	first;
	size_t	last;

	last = ft_strlen(s1) - 1;
	first = 0;
	if (!s1 || !set)
		return (NULL);
	while (s1[first] && to_find(set, s1[first]))
	{
		first++;
	}
	while (s1[last] && to_find(set, s1[last]))
	{
		last--;
	}
	return (ft_substr(s1, first, last - first + 1));
}

// #include <stdio.h>
// int main() {
//     char *s1 = "   !!Hello, World!!   ";
//     char *set = " !";

//     // Appel de la fonction ft_strtrim
//     char *result = ft_strtrim(s1, set);

//     // Vérification du résultat
//     if (result) {
//         printf("Original: '%s'\n", s1);
//         printf("Set: '%s'\n", set);
//         printf("Trimmed: '%s'\n", result);

//         // Libération de la mémoire allouée
//         free(result);
//     } else {
//         printf("Erreur d'allocation de mémoire.\n");
//     }

//     return 0;
// }