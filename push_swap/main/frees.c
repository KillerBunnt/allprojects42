/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdexmund <tdexmund@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 10:58:14 by tdexmund          #+#    #+#             */
/*   Updated: 2024/09/27 10:58:14 by tdexmund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/manditory.h"

void freetable(t_table *hold)
{
	freestack(hold->stacka, hold->stackamax);
	freestack(hold->stackb, hold->stackbmax);
	free(hold);
}

void freestack(t_stack *hold, int stackmax)
{
	if (hold)
	{
		while ((hold->position != stackmax))
			hold = hold->prev;
		while (hold->position != 1)
		{
			hold = hold->next;
			free(hold->prev);
		}
	}
	free(hold);
}