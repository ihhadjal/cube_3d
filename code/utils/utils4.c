/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihhadjal <ihhadjal@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 12:31:34 by ihhadjal          #+#    #+#             */
/*   Updated: 2025/06/30 14:17:41 by ihhadjal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../resources/cube.h"

void	error(int x, int y)
{
	if (x == -1 || y == -1)
	{
		printf("error: no starting position found\n");
		exit (1);
	}
}

int	is_alpha(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
			return (1);
		i++;
	}
	return (0);
}

int	check_xpm(char *str)
{
	if (ft_strncmp(str + ft_strlen(str) - 4, ".xpm", 4))
		return (1);
	return (0);
}