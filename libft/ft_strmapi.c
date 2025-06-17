/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilhasnao <ilhasnao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 13:53:15 by ilhasnao          #+#    #+#             */
/*   Updated: 2024/11/14 11:54:49 by ilhasnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

unsigned int	ft_strlen(char const	*s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int		i;
	unsigned int		l;
	char				*result;

	i = 0;
	l = ft_strlen(s);
	result = (char *)malloc(sizeof(char) *(l + 1));
	if (!result)
		return (NULL);
	if (!s && !f)
	{
		return (NULL);
	}
	while (i < l)
	{
		result[i] = f(i, s[i]);
		i++;
	}
	result[i] = '\0';
	return (result);
}
