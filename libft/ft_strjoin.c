/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilhasnao <ilhasnao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 07:30:49 by ilhasnao          #+#    #+#             */
/*   Updated: 2025/02/11 16:55:59 by ilhasnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*s3;
	char		*start;

	s3 = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!s3)
	{
		free(s3);
		return (NULL);
	}
	start = s3;
	while (*s1)
	{
		*s3++ = *s1++;
	}
	while (*s2)
	{
		*s3++ = *s2++;
	}
	*s3 = '\0';
	return (start);
}

/*#include <stdio.h>
int	main(void)
{
	char const	s1[] = "dddd";
	char const	s2[] = "pppp";
	char		*boogie = ft_strjoin(s1, s2);

	printf("%s", boogie);
	free (boogie);
	return (0);
}*/
