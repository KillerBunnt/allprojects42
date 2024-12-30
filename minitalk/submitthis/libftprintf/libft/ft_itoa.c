/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdexmund <tdexmund@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 15:36:48 by tdexmund          #+#    #+#             */
/*   Updated: 2024/06/24 15:58:39 by tdexmund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*fill(int n, int count, char *send)
{
	int	count2;
	int	check;

	check = 1;
	count2 = 0;
	send[count] = 0;
	if (n < 0)
	{
		count2++;
		send[0] = '-';
		check *= -1;
	}
	while (--count >= count2)
	{
		send[count] = ((n % 10) * check) + '0';
		n /= 10;
	}
	return (send);
}

char	*ft_itoa(int n)
{
	int		count;
	int		temp;
	char	*send;

	count = 0;
	temp = n;
	while (temp >= 1 || temp <= -1)
	{
		count++;
		temp /= 10;
	}
	if (n < 0)
		count++;
	if (n == 0)
		count = 1;
	send = (char *)malloc((count + 1) * sizeof(char));
	if (send == 0)
		return (0);
	return (fill(n, count, send));
}
