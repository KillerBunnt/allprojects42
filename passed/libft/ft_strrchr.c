/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdexmund <tdexmund@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 16:17:56 by tdexmund          #+#    #+#             */
/*   Updated: 2024/06/25 17:14:16 by tdexmund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, unsigned int chr)
{
	int		hold;
	int		count;
	int		door;

	hold = -1;
	door = -1;
	count = -1;
	while (str[++count])
	{
		if ((unsigned char)str[count] == (unsigned char)chr)
			hold = (int)count;
	}
	if (chr == 0)
		return ((char *)(str + count));
	else if (hold == -1)
		return (0);
	return ((char *)(str + hold));
}
