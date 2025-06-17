/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   get_next_line.c									:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: ilhasnao <ilhasnao@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/11/25 09:16:49 by ilhasnao		  #+#	#+#			 */
/*   Updated: 2024/11/26 13:26:04 by ilhasnao		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_oldbuffer(char **buffer, char *temp)
{
	char	*old_buffer;

	old_buffer = *buffer;
	*buffer = ft_sstrjoin(*buffer, temp);
	free(old_buffer);
}

char	*ft_update_buffer(char const *line, char *buffer)
{
	int		i;
	int		index;
	char	*updated_buffer;

	i = 0;
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	index = ft_sstrlen(line);
	if (buffer[i] == '\0')
	{
		return (ft_free(buffer, NULL));
	}
	i++;
	updated_buffer = malloc(sizeof(char) * (ft_sstrlen(buffer) - index + 1));
	if (!updated_buffer)
	{
		free (buffer);
		return (NULL);
	}
	i = 0;
	while (buffer[index] != '\0')
		updated_buffer[i++] = buffer[index++];
	updated_buffer[i] = '\0';
	free(buffer);
	return (updated_buffer);
}

char	*get_next_line(int fd)
{
	static char		*buffer = NULL;
	char			*temp;
	char			*line;
	ssize_t			r_b;

	temp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!temp)
		return (ft_free(buffer, NULL));
	while (!ft_sstrchr(buffer, '\n'))
	{
		r_b = read(fd, temp, BUFFER_SIZE);
		if (r_b <= 0)
		{
			if (r_b == 0)
				break ;
			return (ft_free(buffer, temp));
		}
		temp[r_b] = '\0';
		ft_oldbuffer(&buffer, temp);
	}
	if (!buffer || buffer[0] == '\0')
		return (ft_free(buffer, temp));
	line = ft_sstrdup(buffer);
	buffer = ft_update_buffer(line, buffer);
	return (free(temp), line);
}

// int	main (void)
// {
// 	int fd;
//     char *line;

//     fd = open("Bomboclaat.txt", O_RDONLY);
//     if (fd == -1)
//     {
//         perror("Error opening file");
//         return (1);
//     }

//     // Lire le fichier ligne par ligne
//     while ((line = get_next_line(fd)) != NULL)
//     {
//         printf("%s", line);
//         free(line); // Libérer la mémoire allouée par get_next_line
//     }

//     // Fermer le fichier
//     if (close(fd) == -1)
//     {
//         perror("Error closing file");
//         return (1);
//     }
// }
