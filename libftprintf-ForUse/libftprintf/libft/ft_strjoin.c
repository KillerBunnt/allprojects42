/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdexmund <tdexmund@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 16:02:40 by tdexmund          #+#    #+#             */
/*   Updated: 2024/06/24 16:13:17 by tdexmund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
