/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdexmund <tdexmund@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 15:14:20 by tdexmund          #+#    #+#             */
/*   Updated: 2024/07/29 15:14:22 by tdexmund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list getcurline(int fd, unsigned int line)
{
	char			*buffer;
	t_list			chain;
	unsigned int	count;

	count = 0;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	buffer[BUFFER_SIZE] = 0;
	buffer = read(fd, buffer, BUFFER_SIZE);
	chain.content = buffer;
	while (buffer[count])
	{
		if ((buffer[count] == '\n') && (line == 0))
		{
			chain.next = NULL;
			return (chain);
		}
		count++;
	}
	chain.next = &(getcurline(fd, line--));
	return (chain);
}
