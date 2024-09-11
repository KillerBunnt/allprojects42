/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdexmund <tdexmund@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 12:53:46 by tdexmund          #+#    #+#             */
/*   Updated: 2024/06/24 16:45:32 by tdexmund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	white(char x)
{
	char	*whites;
	int		count;

	count = -1;
	whites = " \t\r\n\v\f";
	while (whites[++count])
	{
		if (x == whites[count])
			return (1);
	}
	return (0);
}

static int	fneg(int *fix, char e)
{
	*fix = 2;
	if (e == '-')
		return (-1);
	return (1);
}

int	ft_atoi(const char *str)
{
	int	count;
	int	send;
	int	fix;
	int	neg;

	fix = 0;
	count = 0;
	send = 0;
	neg = 1;
	while (str[count])
	{
		if (white(str[count]) && (fix < 1))
			fix = 0;
		else if ((str[count] == '+' || str[count] == '-') && (fix < 2))
			neg *= fneg(&fix, str[count]);
		else if (str[count] >= '0' && str[count] <= '9')
		{
			fix = 2;
			send = send * 10 + (str[count] - '0');
		}
		else
			return (send * neg);
		count++;
	}
	return (send * neg);
}
