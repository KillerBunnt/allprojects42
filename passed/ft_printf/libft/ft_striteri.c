/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdexmund <tdexmund@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 14:34:40 by tdexmund          #+#    #+#             */
/*   Updated: 2024/06/24 16:12:57 by tdexmund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	count;
	unsigned int	count2;

	count = 0;
	count2 = 0;
	while (s[count])
		count++;
	while (count2 < count)
	{
		(*f)(count2, &(s[count2]));
		count2++;
	}
}
