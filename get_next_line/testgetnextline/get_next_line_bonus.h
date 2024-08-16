/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdexmund <tdexmund@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 15:14:36 by tdexmund          #+#    #+#             */
/*   Updated: 2024/07/29 15:14:42 by tdexmund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

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

typedef struct s_list
{
	char			*content;
	char			*used;
	char			*curline;
	int				sizeread;
	int				fd;
	int				end;
	int				canfree;
	struct s_list	*prev;
	struct s_list	*next;
}	t_list;

char	*finish(t_list *lineread);
t_list	*getfile(int fd, t_list *lineread);

#endif
