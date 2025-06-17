/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilhasnao <ilhasnao@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:17:40 by ilhasnao          #+#    #+#             */
/*   Updated: 2024/11/05 13:55:24 by ilhasnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	if (s == NULL)
	{
		return (NULL);
	}
	i = ft_strlen((char *)s);
	while (i >= 0)
	{
		if (s[i] == (char) c)
		{
			return ((char *)&s[i]);
		}
		i--;
	}
	return (NULL);
}

// int   main (void)
// {
//         int     c = '\0';
//         const   char test[] = "kayako";

//         printf("%s", ft_strrchr(test, c));
//         return (0);
// }
