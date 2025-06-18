/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilhasnao <ilhasnao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 11:37:31 by ilhasnao          #+#    #+#             */
/*   Updated: 2024/12/08 11:04:37 by ilhasnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char		*buffer;
	size_t		i;

	if (nmemb != 0 && nmemb * size / nmemb != size)
	{
		return (NULL);
	}
	buffer = malloc(nmemb * size);
	i = 0;
	if (!buffer)
	{
		return (NULL);
	}
	while (i < nmemb * size)
	{
		buffer[i] = 0;
		i++;
	}
	return (buffer);
}

/*#include <stdio.h>
int main()
{
    int *arr;
    size_t i;
    size_t len = 5;

    // Appel de ft_calloc pour allouer un tableau de 5 int
    arr = (int *)ft_calloc(len, sizeof(int));

    if (!arr)
    {
        printf("Erreur d'allocation mémoire.\n");
        return (1);
    }

    // Affiche le contenu du tableau après initialisation
    for (i = 0; i < len; i++)KO
    {
        printf("arr[%zu] = %d\n", i, arr[i]);
    }

    // Libération de la mémoire
    free(arr);

    return 0;
}*/
