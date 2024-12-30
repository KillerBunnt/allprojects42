/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo1_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdexmund <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 13:20:13 by tdexmund          #+#    #+#             */
/*   Updated: 2024/12/30 13:20:14 by tdexmund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/manditory.h"

t_stack	*rotatesetup(t_stack *temp, int targetnum, int start, int end);
t_stack	*rotatesetupa(t_stack *temp, int targetnum);

void	setupb(t_table *hold, int targetnum)
{
	unsigned int		pos;
	t_stack				*temp;
	int					num;

	temp = hold->stackb;
	num = hold->stackb->value;
	while (1)
	{
		if (num != targetnum)
			temp = temp->next;
		else
		{
			pos = temp->position;
			break ;
		}
		num = temp->value;
	}
	if (hold->stackb->position - pos < pos)
		while (++pos <= hold->stackbmax)
			rotaterules(hold, 2);
	else if (pos)
		reset(hold, pos, 2);
}

void	setupa(t_table *hold, int targetnum)
{
	t_stack				*temp;
	unsigned int		pos;

	pos = 0;
	temp = hold->stacka;
	temp = rotatesetupa(temp, targetnum);
	if (temp->prev->value < targetnum && temp->value > targetnum)
		pos = temp->position;
	else
	{
		temp = temp->next;
		temp = rotatesetupa(temp, targetnum);
		pos = temp->position;
	}
	if (hold->stacka->position - pos < pos)
		while (++pos <= hold->stackamax)
			rotaterules(hold, 1);
	else if (pos)
		reset(hold, pos, 1);
}

void	sortend(t_table *hold)
{
	int		biggest;

	while (hold->stackbmax)
	{
		biggest = getbiggest(hold->stackb);
		setupb(hold, biggest);
		pushrules(hold, 1);
	}
}

t_stack	*rotatesetup(t_stack *temp, int targetnum, int start, int end)
{
	t_stack	*temp2;

	temp2 = temp;
	while (1)
	{
		if (temp->value < targetnum && temp->prev->value > targetnum)
			return (temp);
		if (start && end && temp->value == start)
		{
			while (temp->prev->value != end)
				temp = temp->next;
			if (temp == temp2)
				return (skippart(start, end, temp, targetnum));
			else
				temp = temp->prev;
		}
		temp = temp->next;
		if (temp == temp2)
			return (getcorrectpos(temp, end, start, targetnum));
	}
	return (temp);
}

t_stack	*rotatesetupa(t_stack *temp, int targetnum)
{
	while (temp->value > temp->prev->value)
	{
		if (temp->value > targetnum && temp->prev->value < targetnum)
			return (temp);
		temp = temp->next;
	}
	return (temp);
}
