/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilhasnao <ilhasnao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 07:11:57 by ilhasnao          #+#    #+#             */
/*   Updated: 2024/11/18 09:35:49 by ilhasnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*mem;

	if (s == NULL)
	{
		return (0);
	}
	mem = s;
	while (n--)
	{
		*mem = (unsigned char)c;
		mem++;
	}
	return (s);
}

/*int     main (void)
{
    int     c = 'a';
    size_t  o = 10;
    void    *test = malloc(o + 1);

    ft_memset(test, c, o);
    ((unsigned char *)test)[o] = '\0';

    printf("%s", (char *)test);
    free(test);
    return (0);
}*/
