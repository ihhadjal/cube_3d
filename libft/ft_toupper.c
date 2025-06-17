/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilhasnao <ilhasnao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 06:57:16 by ilhasnao          #+#    #+#             */
/*   Updated: 2024/11/14 11:46:29 by ilhasnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
	{
		c = c - 32;
		return (c);
	}
	else
	{
		return (c);
	}
}

// int	main(void)
// {
// 	int	a;
// 	//int	b;

// 	a = 100;
// 	a = ft_toupper (a);
// 	write(1, &a, 1);
// 	return (0);
// }
