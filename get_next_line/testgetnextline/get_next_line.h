/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdexmund <tdexmund@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 15:14:36 by tdexmund          #+#    #+#             */
/*   Updated: 2024/07/29 15:14:42 by tdexmund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

char	*get_next_line(int fd);
char	*ft_strjoin(char const *s1, char const *s2);
void	*ft_calloc(size_t size, size_t count);
void	*ft_bzero(void *addr, unsigned int byte);
size_t	ft_strlen(const char *str);


typedef struct s_list
{
	char			*content;
	char			*used;
	char			*curline;
	int				sizeread;
	int				end;
	struct s_list	*next;
}	t_list;

#endif
