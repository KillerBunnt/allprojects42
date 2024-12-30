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

t_table	*inittable(void);

int	checksorted(t_stack *hold)
{
	t_stack	*temp;

	while (hold->value > hold->prev->value)
		hold = hold->prev;
	temp = hold;
	while (hold->value < hold->next->value)
		hold = hold->next;
	if (hold->next == temp)
		return (0);
	return (1);
}

void	simplesort(t_table *hold)
{
	if (hold->stackamax == 2)
	{
		if (hold->stacka->value > hold->stacka->next->value)
			swaprules(hold, 1);
	}
	else if (checksorted(hold->stacka))
	{
		while (hold->stackamax > 3)
			pushrules(hold, 2);
		if (checksorted(hold->stacka))
			startsimplesort(hold);
		else
			rotatecorrect(hold);
		while (hold->stackbmax)
		{
			setupa(hold, hold->stackb->value);
			pushrules(hold, 1);
		}
	}
	while (hold->stacka->value > hold->stacka->prev->value)
		rrotaterules(hold, 1);
}

void	simplesort2(t_table *hold)
{
	t_stack	*temp;

	temp = hold->stacka;
	while (hold->stacka->value > hold->stacka->prev->value)
		rrotaterules(hold, 1);
	while (1)
	{
		while (temp->value < temp->next->value)
			temp = temp->next;
		if (temp->next == hold->stacka)
			break ;
		if (hold->stacka != temp)
		{
			while (hold->stacka != temp->next)
				rotaterules(hold, 1);
		}
		pushrules(hold, 2);
		temp = hold->stacka;
	}
	flushb(hold);
}

int	main(int argcount, char **args)
{
	t_table	*hold;

	hold = NULL;
	if (argcount == 1)
		return (0);
	hold = inittable();
	if (!hold)
		return (1);
	if (checkargs(hold, argcount, args) == 0)
		return (1);
	if (hold->stackamax <= 5)
		simplesort(hold);
	else
		algo1(hold);
	freetable(hold);
}
