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
#include <stdio.h>
static t_list readfile(int fd);
static t_list getcurline(t_list lineread, int fd);

static t_list fillcurline(t_list lineread, unsigned int start, unsigned int end, unsigned int index)
{
	while (index < end)
	{
		if(lineread.content[index] != '\n')
		{
			lineread.curline[start] = lineread.content[index];
			start++;
		}
		lineread.used[index] = lineread.content[index];
		index++;
	}
	return (lineread);
}

static t_list checkend(t_list lineread, int fd, unsigned int end, unsigned int index)
{
	char	*holdcurline;
	char	*temp;

	holdcurline =  ft_strlcpy(holdcurline, lineread.curline, end - index + 1);
	if (end == BUFFER_SIZE)
	{
		free(lineread.content);
		free(lineread.used);
		lineread = readfile(fd);
		lineread = getcurline(lineread, fd);
		temp = ft_strjoin(holdcurline, lineread.curline);
		free(holdcurline);
		free(lineread.curline);
		lineread.curline = temp;
	}
	return (lineread);
}

static t_list getcurline(t_list lineread, int fd)
{
	unsigned int	index;
	unsigned int	end;
	unsigned int	start;

	start = 0;
	end = 0;
	index = 0;
	while (lineread.used[index])
		index++;
	end = index + 1;
	while (lineread.content[end] != '\n' && lineread.content[end])
		end++;
	if (lineread.curline)
		free(lineread.curline);
	lineread.curline = ft_calloc(sizeof(char), end - index + 1);
	lineread = fillcurline(lineread, start, end, index);
	lineread = checkend(lineread, fd, end, index-start);
	return (lineread);
}

static t_list readfile(int fd)
{
	t_list	lineread;

	lineread.curline = NULL;
	lineread.content = ft_calloc(sizeof(char) , (BUFFER_SIZE + 1));
	lineread.sizeread = read(fd, lineread.content, BUFFER_SIZE);
	lineread.used = ft_calloc(sizeof(char) , (lineread.sizeread + 1));
	lineread.content[BUFFER_SIZE] = 0;
	lineread.used[lineread.sizeread] = 0;
	return (lineread);
}

char	*get_next_line(int fd)
{
	static t_list	lineread;
	unsigned int	index;

	index = 0;
	if (!(lineread.content))
		lineread = readfile(fd);
	lineread = getcurline(lineread, fd);
	while (lineread.used[index])
		index++;
	if (index == lineread.sizeread && !lineread.curline[0])
		return (NULL);
	return (lineread.curline);
}
