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

static char *trimbuffer(char *buffer, unsigned int start)
{
	unsigned int index;

	index = 0;
	while (buffer[start++])
	{
		buffer[index] = buffer[start];
		index++;
	}
	buffer[index] = 0;
	return (buffer);
}

static char *fillbuffer(int fd)
{
	static char			buffer[BUFFER_SIZE + 1] = "\0";
	unsigned int		sizeread;

	if (!(buffer[0]))
	{
		sizeread = read(fd, buffer, BUFFER_SIZE);
		buffer[BUFFER_SIZE] = 0;
	}
	return (buffer);
}

static char *ft_getline(int fd, char *buffer)
{
	unsigned int	index;
	char			*useme;
	unsigned int	count;

	count = 0;
	index = 0;
	while (buffer[index] != '\n' && buffer[index])
		index++;
	useme = malloc(sizeof(char) * (index + 1));
	useme[index] = 0;
	while (count < index)
	{
		useme[count] = buffer[count];
		count++;
	}
	trimbuffer(buffer, index);
	if (!(buffer[0]))
	{
		fillbuffer(fd);
		useme = ft_strjoin(useme, ft_getline(fd, buffer));
	}
	return (useme);
}

static char *getcurline(int fd, char *curline)
{
	char *buffer;

	buffer = fillbuffer(fd);
	curline = ft_getline(fd, buffer);

	return (curline);
}


char	*get_next_line(int fd)
{
	char *curline;

	curline = malloc(sizeof(char));
	curline = "\0";
	curline = getcurline(fd, curline);
	if(!(curline[0]))
		return (NULL);
	return (curline);
}
