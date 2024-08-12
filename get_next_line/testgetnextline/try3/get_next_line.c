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

static t_list	readline(int fd, t_list using)
{
	t_list	lineread;

	if (!using.content)
		lineread.content = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	lineread.sizeread = read(fd, lineread.content, BUFFER_SIZE);
	lineread.content[lineread.sizeread] = 0;
	lineread.used = ft_calloc(sizeof(char), lineread.sizeread + 1);
	return (lineread);
}
static t_list	checkmore(int fd, t_list lineread, unsigned int count)
{
	if (!(lineread.used[count]))
	{
		free(lineread.used);
		lineread = readline(fd, lineread);
	}
	if (lineread.sizeread == 0)
		return (lineread);
	else
		lineread = getcurline(fd, lineread);
	return (lineread);
}

static t_list	checkend(int fd, t_list lineread, unsigned int count, unsigned int index)
{
	char			*temp;
	char			*temp2;
	unsigned int	fill;

	fill = 0;
	temp = lineread.curline;
	lineread.curline = ft_calloc(sizeof(char), count - index + 1);
	while (index < count))
	{
		lineread.curline[fill] = lineread.content[index];
		index++;
		fill++;
	}
	temp2 = lineread.curline;
	if (temp)
	{
		lineread.curline = ft_strjoin(temp, temp2);
		free(temp);
		free(temp2);
	}
	lineread = checkmore(fd, lineread, count)
	return (lineread);
}

static t_list	getcurline(int fd, t_list lineread)
{
	unsigned int	index;
	unsigned int	count;

	index = 0;
	while (lineread.used[index])
		index++;
	count = index;
	while (1)
	{
		lineread.used[count] = lineread.content[count];
		if (lineread.used[count] == '\n' || !lineread.used[count])
			break ;
		count++;
	}
	lineread = checkend(fd, lineread.curline, count, index)
	return (lineread);
}

char	*get_next_line(int fd)
{
	static t_list lineread;

	if (!lineread.content)
		lineread = readline(fd, lineread);
	lineread = getcurline(fd, lineread);
}
