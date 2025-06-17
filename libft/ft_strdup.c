/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilhasnao <ilhasnao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 11:13:37 by ilhasnao          #+#    #+#             */
/*   Updated: 2025/02/17 17:29:50 by ilhasnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_strlen(const char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strdup(const char *s)
{
	int		i;
	char	*dest;

	dest = malloc(sizeof(char) * ft_strlen(s) + 1);
	i = 0;
	if (dest == NULL)
	{
		return (NULL);
	}
	while (s[i] != '\0')
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

// #include <stdio.h>
// int     main(void)
// {       
//         const char str[] = "soso maness so so so maness";
//         char *duplicated_str = ft_strdup(str);
//         if (duplicated_str == NULL)
//         {
//                 printf("Memory allocation failed\n");
//                 return (1);
//         }
//         printf("%s\n", duplicated_str);
//         free(duplicated_str);
//         return (0);
// }
