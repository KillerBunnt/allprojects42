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
static char *getback(char *buffer)
{
	char			*temp;
	unsigned int	index;

	index = 0;
	while (buffer[index] != '\n')
		index++;
	temp = malloc(sizeof(char) * (BUFFER_SIZE - index + 1));
	while (index++ < BUFFER_SIZE)
	{
		temp[index] = buffer[index];
	}
	temp[index] = 0;
	return (temp);
}

static char *getuse(char *useme, char *buffer, unsigned int sizeread, unsigned int *sizeused)
{
	unsigned int	index;
	unsigned int	count;

	count = 0;
	index = 0;
	while (index < sizeread)
	{
		if (buffer[index] == '\n')
			break ;
		index++;
	}
	useme = malloc(sizeof(char) * (index + 1));
	while(count < index)
	{
		useme[count] = buffer[count];
		count++;
	}
	useme[count] = 0;
	*sizeused = index;
	return (useme);
}

static char *getcurline(int fd, char *curline)
{
	static char			buffer[BUFFER_SIZE] = "\0";
	char				*useme;
	char 				*temp;
	unsigned int		sizeread;
	unsigned int		sizeused;

	if (buffer[0])
		curline = getback(buffer);
		printf("%s\n",buffer);
	while (1)
	{
		sizeread = read(fd, buffer, BUFFER_SIZE);
		useme = getuse(useme, buffer, sizeread, &sizeused);
		curline = ft_strjoin(curline, useme);
		free(useme);
		if (sizeused != BUFFER_SIZE)
			break ;
	}
	if (sizeread <= 0)
		return (NULL);
	return (curline);
}


char	*get_next_line(int fd)
{
	char *curline;

	curline = malloc(sizeof(char));
	curline = "\0";
	curline = getcurline(fd, curline);
	if(!(curline))
		return (NULL);
	return (curline);
}
