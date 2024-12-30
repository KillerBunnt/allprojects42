/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdexmund <tdexmund@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 16:23:17 by tdexmund          #+#    #+#             */
/*   Updated: 2024/07/22 16:23:19 by tdexmund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_u(unsigned int dig, int *countme)
{
	if (dig > 9)
		print_u (dig / 10, &(*countme));
	ft_putnbr_fd ((int)(dig % 10), 1);
	*countme += 1;
}
