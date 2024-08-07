/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdexmund <tdexmund@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 15:13:56 by tdexmund          #+#    #+#             */
/*   Updated: 2024/07/29 15:13:57 by tdexmund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	t_list			curline;
	static int		hold = 0;
	static int		index = 0;
	static int		count = 0;
	char			returnme;

	count++;
	curline = getcurline(fd);
	while (true)
	{
		if ((curline.content)[index] == '\n')
		{
			write(1, curline.content, index + 1);
			hold = index;
			break ;
		}
		else if ((curline.content)[index] == 0)
		{
			write(1, curline.content, BUFFER_SIZE - (index * (hold == 0)));
			curline = *curline.next;
			index = 0;
			hold = 0;
		}
		index++;
	}
}
