/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdexmund <tdexmund@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 15:14:20 by tdexmund          #+#    #+#             */
/*   Updated: 2024/08/18 02:35:58 by tdexmund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strjoin(char *s1, char *s2)
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
	free(s1);
	free(s2);
	return (temp);
}

size_t	ft_strlen(const char *str)
{
	int	num;

	num = 0;
	while (str[num])
		num++;
	return (num);
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

void	ft_reset(t_list *file, int end)
{
	int	start;

	start = -1;
	if (file->content)
	{
		while (file->content[end])
			file->content[++start] = file->content[end++];
		file->content[++start] = file->content[end++];
	}
}
