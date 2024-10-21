/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdexmund <tdexmund@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 16:00:03 by tdexmund          #+#    #+#             */
/*   Updated: 2024/06/25 17:12:32 by tdexmund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(char *str, unsigned int chr)
{
	int	count;

	count = -1;
	while (str[++count])
	{
		if ((unsigned char)str[count] == (unsigned char)chr)
			return (str + count);
	}
	if (chr == 0)
		return (str + count);
	return (0);
}
