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
	while (s1[++count] && s1 != NULL)
		temp[count] = s1[count];
	count--;
	size = -1;
	while (s2[++size] && s2 != NULL)
		temp[++count] = s2[size];
	temp[count + 1] = 0;
	return (temp);
}