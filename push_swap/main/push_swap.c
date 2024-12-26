/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdexmund <tdexmund@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 15:45:31 by tdexmund          #+#    #+#             */
/*   Updated: 2024/09/26 15:45:31 by tdexmund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/manditory.h"

t_table	*inittable();

int main(int argcount, char **args)
{
	t_table *hold;

	hold = NULL;
	if (argcount == 1)
		return (0);
	hold = inittable();
	if (checkargs(hold, argcount, args) == 0)
		return (0);
	algo1(hold);
	freetable(hold);
}