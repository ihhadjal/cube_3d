/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilhasnao <ilhasnao@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 11:50:38 by ilhasnao          #+#    #+#             */
/*   Updated: 2024/11/11 12:02:51 by ilhasnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
		{
			return ((char *)&s[i]);
		}
		i++;
	}
	if (c == '\0')
	{
		return ((char *)&s[i]);
	}
	return (NULL);
}

/*int	main (void)
{
	int	c = 'z';
	const	char test[] = "kayako";

	printf("%s\n", ft_strchr(test, c));
	return (0);
}*/
