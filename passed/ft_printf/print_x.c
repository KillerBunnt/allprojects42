/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdexmund <tdexmund@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 16:22:40 by tdexmund          #+#    #+#             */
/*   Updated: 2024/07/23 14:46:29 by tdexmund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	printout(unsigned int baset, char *hexes, int *countme);

int	print_x(unsigned int baset, char form)
{
	char	*hexes;
	int		countme;

	countme = 0;
	hexes = "0123456789abcdef";
	if (form == 'X')
		hexes = "0123456789ABCDEF";
	printout(baset, hexes, &countme);
	return (countme);
}

static void	printout(unsigned int baset, char *hexes, int *countme)
{
	if (baset > 15)
		printout (baset / 16, hexes, countme);
	if (baset < 16)
		write(1, &(hexes[baset]), 1);
	else
		write(1, &(hexes[baset % 16]), 1);
	*countme += 1;
}
