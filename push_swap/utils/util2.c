/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdexmund <tdexmund@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 15:45:35 by tdexmund          #+#    #+#             */
/*   Updated: 2024/09/26 15:45:35 by tdexmund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/manditory.h"

int	getsmallest(t_stack *hold)
{
	t_stack	*temp;
	int		smallest;

	smallest = hold->value;
	temp = hold->next;
	while (temp != hold)
	{
		if (temp->value < smallest)
			smallest = temp->value;
		temp = temp->next;
	}
	return (smallest);
}

int	getbiggest(t_stack *hold)
{
	t_stack	*temp;
	int		biggest;

	biggest = hold->value;
	temp = hold->next;
	while (temp != hold)
	{
		if (temp->value > biggest)
			biggest = temp->value;
		temp = temp->next;
	}
	return (biggest);
}

void	flushb(t_table *hold)
{
	while (hold->stackb)
	{
		while (hold->stacka->value < hold->stackb->value)
			rotaterules(hold, 1);
		pushrules(hold, 1);
		while (hold->stacka->value > hold->stacka->prev->value)
			rrotaterules(hold, 1);
	}
}

void	startsimplesort(t_table *hold)
{
	if (hold->stacka->value == getsmallest(hold->stacka))
	{
		if (hold->stackb
			&& hold->stackb->value < hold->stackb->next->value)
			rotaterules(hold, 3);
		else
			rotaterules(hold, 1);
	}
	else if (hold->stacka->next->value == getsmallest(hold->stacka))
	{
		if (hold->stackb
			&& hold->stackb->value < hold->stackb->next->value)
			rrotaterules(hold, 3);
		else
			rrotaterules(hold, 1);
	}
	if (hold->stacka->value > hold->stacka->next->value)
		swaprules(hold, 1);
}

void	rotatecorrect(t_table *hold)
{
	if (hold->stacka->value > hold->stacka->prev->value)
	{
		if (hold->stacka->value < hold->stacka->next->value)
			rrotaterules(hold, 1);
		else
			rotaterules(hold, 1);
	}
}
