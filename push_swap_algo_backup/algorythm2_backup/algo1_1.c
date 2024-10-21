/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo1_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdexmund <tdexmund@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 15:47:31 by tdexmund          #+#    #+#             */
/*   Updated: 2024/09/26 15:47:31 by tdexmund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/manditory.h"

t_stack *rotatesetup(t_stack *temp, int targetnum);
void endsort(t_table *hold);

int algo1(t_table *hold)
{
	t_stack *temp;
	t_stack *temp2;
	int count;

	count = hold->stackamax / 8;
	while (--count >= 0)
	{
		pushrules(hold, 2);
		pushrules(hold, 2);

		temp = hold->stacka;
		temp2 = hold->stackb;

		if (temp2->value < temp2->next->value 
			&& temp->value > temp->next->value)
			swaprules(hold, 3);
		else if (temp2->value < temp2->next->value)
			swaprules(hold, 2);
		else if (temp->value > temp->next->value)
			swaprules(hold, 1);
		temp = hold->stackb;
		temp2 = hold->stackb->next;
		if (hold->stacka->value < hold->stackb->value)
			rotaterules(hold, 2);
		if (hold->stacka->value < hold->stackb->value)
			rotaterules(hold, 2);
		pushrules(hold, 2);
		if (hold->stackb->prev == temp || hold->stackb->prev == temp2)
			while (hold->stacka->value > hold->stackb->prev->value)
			{
				if (hold->stackb == temp)
					break;
				rrotaterules(hold, 2);
			}
		pushrules(hold, 2);
		if (hold->stackb->prev == temp || hold->stackb->prev == temp2)
			while (hold->stackb != temp)
				rrotaterules(hold, 2);
	}
	endsort(hold);
	return (0);
}

void setup(t_table *hold, int targetnum)
{
	t_stack				*temp;
	unsigned int		pos;

	pos = 0;
	temp = hold->stacka;
	temp = rotatesetup(temp, targetnum);
	if (temp->prev->value < targetnum && temp->value > targetnum)
		pos = temp->position;
	else
	{
		temp = temp->next;
		temp = rotatesetup(temp, targetnum);
		pos = temp->position;
	}
	if (hold->stacka->position - pos < pos)
		while (++pos <= hold->stackamax)
			rotaterules(hold, 1);
	else if (pos)
	{
		while(pos--)
			rrotaterules(hold, 1);
	}
}

void endsort(t_table *hold)
{
	while (hold->stackbmax)
	{
		if (hold->stackamax > 1)
			setup(hold, hold->stackb->value);
		// ft_printf("hi");
		pushrules(hold, 1);
	}
}

t_stack *rotatesetup(t_stack *temp, int targetnum)
{
	while (temp->value > temp->prev->value)
	{
		if (temp->value > targetnum && temp->prev->value < targetnum)
			return (temp);
		temp = temp->next;
	}
	return (temp);
}