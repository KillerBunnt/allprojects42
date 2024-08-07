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
# define BUFFER_SIZE = 69

# include <unistd.h>

char	*get_next_line(int fd);

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

#endif
