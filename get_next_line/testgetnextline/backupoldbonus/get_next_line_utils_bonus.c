/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdexmund <tdexmund@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 15:14:20 by tdexmund          #+#    #+#             */
/*   Updated: 2024/07/29 15:14:22 by tdexmund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*temp;
	int		count;
	int		size;

	count = 0;
	size = 0;
	while (s1[count])
		count++;
	while (s2[size])
		size++;
	size += (count + 1);
	count = -1;
	temp = (char *)malloc(size * sizeof(char));
	if (temp == 0)
		return (0);
	while (s1[++count])
		temp[count] = s1[count];
	count--;
	size = -1;
	while (s2[++size])
		temp[++count] = s2[size];
	temp[count + 1] = 0;
	return (temp);
}

void	*ft_calloc(size_t size, size_t count)
{
	char			*temp;
	size_t			count2;

	count2 = 0;
	temp = malloc(count * size);
	if (temp == 0)
		return (0);
	while (count2 < count)
	{
		temp[count2] = 0;
		count2++;
	}
	return ((void *)temp);
}

void	*ft_bzero(void *addr, unsigned int byte)
{
	unsigned int	count;
	char			*test;

	test = addr;
	count = 0;
	while (count < byte)
	{
		test[count] = 0;
		count++;
	}
	return ((void *)test);
}

int	finish(t_list *lineread)
{
	unsigned int	linesize;

	linesize = lineread->sizeread;
	if (lineread->end || !linesize || ((linesize < BUFFER_SIZE)
			&& lineread->content[linesize - 1] == lineread->used[linesize - 1]))
	{
		lineread->end = 1;
		free(lineread->content);
		free(lineread->used);
		return (1);
	}
	return (0);
}

t_list	*getfile(int fd, t_list *lineread)
{
	t_list	initial;

	while (lineread->fd != fd)
	{
		if (!lineread->next)
		{
			initial.content = NULL;
			initial.used = NULL;
			initial.curline = NULL;
			initial.fd = fd;
			initial.end = 0;
			initial.sizeread = 0;
			initial.next = NULL;
			lineread->next = &initial;
		}
		lineread = lineread->next;
	}
	return (lineread);
}
