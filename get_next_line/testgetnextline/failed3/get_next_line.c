/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdexmund <tdexmund@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 15:13:56 by tdexmund          #+#    #+#             */
/*   Updated: 2024/08/18 02:21:06 by tdexmund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
void	readline(int fd, t_list *file);

static t_list	*makenewfile(int fd)
{
	t_list	*newfile;

	newfile = malloc(sizeof(t_list));
	newfile->content = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	newfile->curline = NULL;
	newfile->sizeread = 0;
	newfile->end = 0;
	newfile->next = NULL;
	return (newfile);
}

char	*ft_getline(int fd, t_list *file)
{
	char	*temp;

	temp = file->curline;
	printf("(%c)",file->content[0]);
	if (!file->content[0])
	{
		file->sizeread = read(fd, file->content, BUFFER_SIZE);
		file->content[ft_strlen(file->content)] = 0;
		if (file->sizeread < 0)
		{
			ft_bzero(file->content, BUFFER_SIZE);
			return (NULL);
		}
		if (!file->sizeread)
		{
			free(file->content);
			free(file);
			if (temp[0])
				return (temp);
			else
				return (NULL);
		}
	}
	readline(fd, file);
	return (file->curline);
}

void	reset(t_list *file, int end)
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
	reset(file, end);
	if (file->curline)
		ft_strjoin(file->curline, temp);
	else
		file->curline = temp;
	if (file->curline[ft_strlen(file->curline) - 1] != '\n' && file->sizeread == BUFFER_SIZE)
		ft_getline(fd, file);
}

char	*get_next_line(int fd)
{
	static t_list	*file;
	char			*temp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!file)
		file = makenewfile(fd);
	return (ft_getline(fd, file));
}
