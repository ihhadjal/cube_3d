/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilhasnao <ilhasnao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 09:58:18 by ilhasnao          #+#    #+#             */
/*   Updated: 2024/11/14 11:27:08 by ilhasnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	get_num_char(long n)
{
	int	i;

	i = 0;
	if (n <= 0)
	{
		i = 1;
		n = -n;
	}
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

void	convert_number(char *result, long num, int index_end)
{
	if (num == 0)
	{
		result[0] = '0';
		return ;
	}
	if (num < 0)
	{
		result[0] = '-';
		num = -num;
	}
	while (num > 0)
	{
		result[--index_end] = (num % 10) + '0';
		num = num / 10;
	}
}

char	*ft_itoa(int n)
{
	char	*result;
	long	index_end;
	long	num;

	num = n;
	index_end = get_num_char(n);
	result = malloc(sizeof(char) * (index_end + 1));
	if (!result)
		return (NULL);
	result[index_end] = '\0';
	convert_number(result, num, index_end);
	return (result);
}

// #include <stdio.h>
// int	main(void)
// {
// 	char	*resultat;

// 	resultat = ft_itoa(65416);
// 	printf("%s", resultat);
// 	free(resultat);
// }
