/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdexmund <tdexmund@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 15:13:56 by tdexmund          #+#    #+#             */
/*   Updated: 2024/08/18 03:33:17 by tdexmund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h>
void	readline(int fd, t_list *file);

static t_list	*makenewfile(int fd, t_list *curfile)
{
	t_list	*newfile;

	newfile = malloc(sizeof(t_list));
	newfile->prev = curfile;
	if (curfile)
		curfile->next = newfile;
	newfile->fd = fd;
	newfile->content = ft_calloc(sizeof(char), (BUFFER_SIZE + 1));
	newfile->curline = NULL;
	newfile->sizeread = read(fd, newfile->content, BUFFER_SIZE);
	if (!newfile->sizeread || newfile->sizeread < 0)
	{
		free(newfile->content);
		free(newfile);
		return (curfile);
	}
	newfile->next = NULL;
	return (newfile);
}

char	*ft_getline(int fd, t_list *file)
{
	char	*temp;

	temp = file->curline;
	if (!file->content[0])
	{
		ft_bzero(file->content, BUFFER_SIZE);
		file->sizeread = read(fd, file->content, BUFFER_SIZE);
		file->content[ft_strlen(file->content)] = 0;
		if (file->sizeread < 0)
		{
			ft_bzero(file->content, BUFFER_SIZE);
			if (file->curline)
				ft_bzero(file->curline, ft_strlen(file->curline));
			return (NULL);
		}
		if (!file->sizeread)
		{
			if (temp && temp[0])
				return (temp);
			else
				return (NULL);
		}
	}
	readline(fd, file);
	return (file->curline);
}

void	ft_reset(t_list *file, int end)
{
	int	start;

	start = -1;
	while (file->content[end])
		file->content[++start] = file->content[end++];
	file->content[++start] = file->content[end++];
}

void	readline(int fd, t_list *file)
{
	int		start;
	int		end;
	char	*temp;

	start = -1;
	end = 0;
	while (file->content[end] && file->content[end] != '\n')
		end++;
	if (file->content[end])
		end++;
	if (!end)
		return ;
	temp = malloc(sizeof(char) * (end - start));
	temp[end] = 0;
	while (++start < end)
		temp[start] = file->content[start];
	ft_reset(file, end);
	if (file->curline)
		file->curline = ft_strjoin(file->curline, temp);
	else
		file->curline = temp;
	if (file->curline[ft_strlen(file->curline) - 1] != '\n')
		ft_getline(fd, file);
}

char	*get_next_line(int fd)
{
	static t_list	*file;
	void			*temp;

	temp = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (file && file->prev)
		file = file->prev;
	while (file && (file->fd != fd))
	{
		temp = file;
		file = file->next;
	}
	if (!file)
	{
		file = makenewfile(fd, temp);
		if (file == temp)
			return (NULL);
	}
	file->curline = NULL;
	temp = ft_getline(fd, file);
	if (temp && ((char *)temp)[0])
		return (temp);
	else if (temp)
		free(temp);
	free(file->content);
	if (file->prev)
		file->prev->next = file->next;
	if (file->next)
		file->next->prev = file->prev;
	if (file->prev)
		temp = file->prev;
	else
		temp = file->next;
	free (file);
	file = temp;
	return (NULL);
}
