/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihhadjal <ihhadjal@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:00:32 by ilhasnao          #+#    #+#             */
/*   Updated: 2025/07/10 15:04:42 by ihhadjal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

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
	size_t	len;

	if (!s1 || !set)
		return (NULL);
	len = ft_strlen(s1);
	if (len == 0)
		return (ft_strdup(""));
	last = len - 1;
	first = 0;
	while (s1[first] && to_find(set, s1[first]))
	{
		first++;
	}
	while (last > first && to_find(set, s1[last]))
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