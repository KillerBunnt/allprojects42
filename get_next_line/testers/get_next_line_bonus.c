/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdexmund <tdexmund@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 15:13:56 by tdexmund          #+#    #+#             */
/*   Updated: 2024/07/29 15:13:57 by tdexmund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static t_list	getcurline(int fd, t_list lineread);

static t_list	readline(int fd, t_list using)
{
	if (!using.content)
		using.content = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	else
		using.content = ft_bzero(using.content, BUFFER_SIZE);
	using.sizeread = read(fd, using.content, BUFFER_SIZE);
	using.content[using.sizeread] = 0;
	using.used = ft_calloc(sizeof(char), using.sizeread + 1);
	return (using);
}

static t_list	checkmore(int fd, t_list lineread, unsigned int count)
{
	if (!lineread.used[count])
	{
		free(lineread.used);
		lineread = readline(fd, lineread);
		if (lineread.sizeread)
			lineread = getcurline(fd, lineread);
	}
	return (lineread);
}

static t_list	checkend(int fd, t_list lineread, unsigned int count
	, unsigned int index)
{
	char			*temp;
	char			*temp2;
	unsigned int	fill;

	fill = 0;
	temp = lineread.curline;
	lineread.curline = ft_calloc(sizeof(char), count - index + 1);
	while (index <= count)
	{
		lineread.curline[fill] = lineread.content[index];
		index++;
		fill++;
	}
	lineread.curline[fill] = 0;
	temp2 = lineread.curline;
	if (temp)
	{
		lineread.curline = ft_strjoin(temp, temp2);
		free(temp);
		free(temp2);
	}
	if (lineread.used[count] != '\n')
		lineread = checkmore(fd, lineread, count);
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
	lineread = checkend(fd, lineread, count, index);
	if (!lineread.curline[0])
	{
		free(lineread.curline);
		lineread.curline = NULL;
	}
	return (lineread);
}

char	*get_next_line(int fd)
{
	static t_list	firstfd;
	t_list			*lineread;

	lineread = &firstfd;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	if (firstfd.fd && firstfd.fd != fd)
		lineread = getfile(fd, lineread);
	if (firstfd.fd == fd && lineread->end)
		return (NULL);
	if (!lineread->content)
	{
		*lineread = readline(fd, *lineread);
		lineread->fd = fd;
	}
	lineread->curline = NULL;
	*lineread = getcurline(fd, *lineread);
	return (finish(lineread));
}
