/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdexmund <tdexmund@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 16:00:49 by tdexmund          #+#    #+#             */
/*   Updated: 2024/06/24 18:09:00 by tdexmund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *src)
{
	char	*temp;
	int		count;
	int		count2;

	count = 0;
	count2 = -1;
	while (src[count])
	{
		count++;
	}
	temp = malloc((count + 1) * sizeof(char));
	if (temp == 0)
		return (0);
	while (++count2 < (count + 1))
	{
		temp[count2] = src[count2];
	}
	return (temp);
}
