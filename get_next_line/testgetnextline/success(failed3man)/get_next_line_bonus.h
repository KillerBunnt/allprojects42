/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdexmund <tdexmund@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 15:14:36 by tdexmund          #+#    #+#             */
/*   Updated: 2024/08/18 02:36:23 by tdexmund         ###   ########.fr       */
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
char	*ft_strjoin(char *s1, char *s2);
void	*ft_calloc(size_t size, size_t count);
void	*ft_bzero(void *addr, unsigned int byte);
size_t	ft_strlen(const char *str);

typedef struct s_list
{
	char			*content;
	char			*curline;
	int				sizeread;
	int				fd;
	struct s_list	*prev;
	struct s_list	*next;
}	t_list;
void	ft_reset(t_list *file, int end);
int		finish(t_list *lineread);

#endif
