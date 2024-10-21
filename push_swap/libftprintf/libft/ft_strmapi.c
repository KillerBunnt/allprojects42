/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdexmund <tdexmund@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 16:11:47 by tdexmund          #+#    #+#             */
/*   Updated: 2024/06/24 16:15:12 by tdexmund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	count;
	unsigned int	count2;
	char			*temp;

	count = 0;
	count2 = 0;
	while (s[count])
		count++;
	temp = (char *)malloc((count + 1) * sizeof(char));
	if (temp == 0)
		return (0);
	temp[count] = 0;
	while (count2 < count)
	{
		temp[count2] = (*f)(count2, s[count2]);
		count2++;
	}
	return (temp);
}
