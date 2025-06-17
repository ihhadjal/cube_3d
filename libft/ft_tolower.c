/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilhasnao <ilhasnao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 06:42:21 by ilhasnao          #+#    #+#             */
/*   Updated: 2024/11/14 11:55:22 by ilhasnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
	{
		c = c + 32;
		return (c);
	}
	else
	{
		return (c);
	}
}

// int	main (void)
// {
// 	int	a;
// 	int	b;

// 	a = 67;
// 	b = ft_tolower(a);
// 	write(1, &b, 1);
// 	return (0);
// }
