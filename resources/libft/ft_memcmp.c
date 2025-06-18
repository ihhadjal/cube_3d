/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilhasnao <ilhasnao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 19:26:53 by ilhasnao          #+#    #+#             */
/*   Updated: 2024/11/14 11:26:28 by ilhasnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char		*tab;
	const unsigned char		*bat;
	size_t					i;

	i = 0;
	tab = s1;
	bat = s2;
	while (i < n)
	{
		if (tab[i] > bat[i])
		{
			return (1);
		}
		else if (tab[i] < bat[i])
		{
			return (-1);
		}
		i++;
	}
	return (0);
}

/*#include <stdio.h>
#include <string.h>

int main() {
    const char *str1 = "Hello World!";
    const char *str2 = "Hello World!";
    const char *str3 = "Hello WorlD!";
    const char *str4 = "Hello there!";

    printf("Comparaison de str1 et str2 : %d\n", ft_memcmp(str1, str2, 12));
    printf("Comparaison de str1 et str3 : %d\n", ft_memcmp(str1, str3, 12));
    printf("Comparaison de str1 et str4 : %d\n", ft_memcmp(str1, str4, 12));

    return 0;
}*/
