/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilhasnao <ilhasnao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:52:15 by ilhasnao          #+#    #+#             */
/*   Updated: 2024/11/14 11:52:54 by ilhasnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t					i;
	const unsigned char		*buffer;

	if (s == NULL)
	{
		return (NULL);
	}
	i = 0;
	buffer = s;
	while (i < n)
	{
		if (buffer[i] == (unsigned char) c)
		{
			return ((void *)&buffer[i]);
		}
		i++;
	}
	return (NULL);
}

/*int main(void)
{
    int e = 'y';
    const void *d = "bouyaka";
    size_t r = 7;  // Taille de la chaîne à rechercher
    char *result = ft_memchr(d, e, r);

    if (result != NULL)
    {
        printf("Caractère trouvé : %s\n", result);
    }
    else
    {
        printf("Caractère non trouvé dans les %zu premiers caractères.\n", r);
    }

    return 0;
}*/

/*int	main (void)
{
	int e = 'y';
	const void *d = "bouyaka";
	size_t r = 5;

	printf("%s", ft_memchr(d, e, r));
	return (0);
}*/
