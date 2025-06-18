/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilhasnao <ilhasnao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 08:10:39 by ilhasnao          #+#    #+#             */
/*   Updated: 2024/11/14 11:50:02 by ilhasnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <string.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char			*mem;
	const char		*buffer;
	size_t			i;

	i = 0;
	mem = dest;
	buffer = src;
	while (i < n)
	{
		mem[i] = buffer[i];
		i++;
	}
	return (dest);
}

/*int main(void) {
    size_t o = 10;
    void *test = malloc(o);
    const char tset[] = "kayako"; // Cela reste un tableau de caractères

    // Copie avec la taille de tset au lieu de o
    ft_memcpy(test, tset, o); // Inclut le caractère nul

    write(1, test, o); // Écriture jusqu'à la longueur de tset
    free(test);
    return 0;
}*/

/*int	main (void)
{
	size_t	o = 10;
	void	*test = malloc(o) ;
	const char	tset[] = "kayako";

	ft_memcpy (test, tset, o + 1);
	write(1, test, o);
	free(test);
	return (0);
}*/
