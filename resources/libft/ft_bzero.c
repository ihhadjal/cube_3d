/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilhasnao <ilhasnao@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 07:46:30 by ilhasnao          #+#    #+#             */
/*   Updated: 2024/11/11 14:13:45 by ilhasnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*mem;

	mem = s;
	while (n--)
	{
		*mem++ = 0;
	}
}

/*int	main(void)
{
	size_t	o = 10;
	void	*test = malloc(o);

	ft_bzero (test, o);
	write(1, test, 0);
	free (test);
	return (0);
}*/
