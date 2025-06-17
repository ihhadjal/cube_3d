/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilhasnao <ilhasnao@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 06:43:15 by ilhasnao          #+#    #+#             */
/*   Updated: 2024/11/12 06:55:19 by ilhasnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr_fd(char *s, int fd)
{
	while (*s)
	{
		write(fd, s, 1);
		s++;
	}
}

/*int	main (void)
{
	int	d = 2;
	char	t[] = "da gyal";

	ft_putstr_fd(t, d);
	return (0);
}*/
