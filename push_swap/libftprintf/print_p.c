/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdexmund <tdexmund@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 14:41:44 by tdexmund          #+#    #+#             */
/*   Updated: 2024/07/29 14:26:22 by tdexmund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static void	printout(unsigned long long baset, char *hexes, int *count)
{
	if (baset > 15)
		printout (baset / 16, hexes, &(*count));
	if (baset < 16)
		write(1, &(hexes[baset]), 1);
	else
		write(1, &(hexes[baset % 16]), 1);
	*count += 1;
}

int	print_p(void *str)
{
	unsigned long long	address;
	char				*hexes;
	int					count;

	count = 2;
	address = (unsigned long long)str;
	ft_putstr_fd("0x", 1);
	hexes = "0123456789abcdef";
	printout(address, hexes, &count);
	return (count);
}
