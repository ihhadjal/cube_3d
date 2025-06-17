/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilhasnao <ilhasnao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 10:05:17 by ilhasnao          #+#    #+#             */
/*   Updated: 2024/11/14 11:48:09 by ilhasnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (little[0] == '\0')
	{
		return ((char *)big);
	}
	i = 0;
	while (big[i] != '\0' && i < len)
	{
		j = 0;
		while (big [i + j] == little [j] && (i + j) < len)
		{
			j++;
		}
		if (little [j] == '\0')
		{
			return ((char *)&big[i]);
		}
		i++;
	}
	return (NULL);
}

// #include <stdio.h>
// int	main(void)
// {
// 	const char	bomboclaat[] = "real badman fa da gyal";
// 	const char	badman[] = "badman";
// 	size_t		len = 20;

// 	printf("%s", ft_strnstr(bomboclaat, badman, len));
// 	return (0);
// }