/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo1_help1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdexmund <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 13:20:23 by tdexmund          #+#    #+#             */
/*   Updated: 2024/12/30 13:20:25 by tdexmund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/manditory.h"

t_stack	*skippart(int start, int end, t_stack *temp, int targetnum)
{
	while (temp->value != start)
		temp = temp->next;
	if (temp->prev->value < targetnum)
	{
		while (temp->prev->value != end)
			temp = temp->next;
	}
	return (temp);
}

t_stack	*getcorrectpos(t_stack *temp, int end, int start, int targetnum)
{
	while (temp->value < temp->prev->value && temp->value != start)
		temp = temp->next;
	if (temp->prev->value < targetnum)
	{
		while (end && temp->prev->value != end)
			temp = temp->next;
	}
	return (temp);
}

void	reset(t_table *hold, unsigned int pos, int mode)
{
	while (1)
	{
		rrotaterules(hold, mode);
		if (!(--pos))
			break ;
	}
}

void	process(t_table *hold, int smallest, int biggest, int chunksize)
{
	t_stack	*cuck;

	cuck = hold->stacka;
	while (hold->stacka)
	{
		if (hold->stacka->value >= smallest
			&& hold->stacka->value <= biggest)
		{
			pushrules(hold, 2);
			if (hold->stackb->value <= smallest + chunksize)
				rotaterules(hold, 2);
		}
		else
			rotaterules(hold, 1);
		if (hold->stackb && (hold->stackb == cuck
				|| hold->stackb->prev == cuck))
			cuck = hold->stacka;
		else if (!hold->stacka || cuck == hold->stacka)
			break ;
	}
}
