/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilhasnao <ilhasnao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 09:51:29 by ilhasnao          #+#    #+#             */
/*   Updated: 2024/11/14 11:21:12 by ilhasnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char			*mem;
	const char		*buffer;

	if (dest == NULL || src == NULL || n == 0)
		return (dest);
	mem = dest ;
	buffer = src;
	if (dest <= src)
	{
		while (n--)
		{
			*mem++ = *buffer++;
		}
	}
	else
	{
		mem = mem + n - 1;
		buffer = buffer + n - 1;
		while (n--)
		{
			*mem-- = *buffer--;
		}
	}
	return (dest);
}

// int	main (void)
// {
// 	size_t o = 10;
// 	void	*test = malloc(o);
// 	const char tset[] = "obama";
// 	ft_memmove(test, tset, o);
// 	write(1, test, o);
// 	free(test);
// 	return (0);
// }