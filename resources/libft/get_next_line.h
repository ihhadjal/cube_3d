/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasnawww <hasnawww@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 14:33:09 by ilhasnao          #+#    #+#             */
/*   Updated: 2025/01/28 17:43:32 by hasnawww         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
size_t	ft_sstrlen(const char *str);
char	*ft_sstrjoin(char *s1, char *s2);
char	*ft_sstrdup(char *s);
int		ft_sstrchr(const char *s, int c);
void	ft_oldbuffer(char **buffer, char *temp);
char	*ft_update_buffer(char const *line, char *buffer);
void	*ft_free(char *buffer, char *temp);

#endif