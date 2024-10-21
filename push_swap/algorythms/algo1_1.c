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

int presortcheck(t_stack *stack)
{
	int 	count;
	int		count2;
	t_stack *temp;

	temp = stack;
	count = 0;
	count2 = 1;
	while (temp->value > temp->prev->value)
	{
		temp = temp->prev;
		count++;
	}
	temp = stack;
	while (temp->value < temp->next->value)
	{
		temp = temp->next;
		count2++;
	}
	if (count < count2)
		return (count);
	if (stack->value < stack->next->value)
		return (count2 * -1);
	return (count2 * -1);
}

void presort(t_table *stacks)
{
	int premoves;

	premoves = presortcheck(stacks->stacka);
	while (premoves != 0)
	{
		if (premoves > 0)
		{
			premoves--;
			rrotaterules(stacks, 1);
		}
		else
		{
			premoves++;
			rotaterules(stacks, 1);
		}
	}
}

t_stack *check(t_table *hold, int *counthold)
{
	t_stack *temp;
	t_stack *returnme;
	int count;

	count = 0;
	returnme = hold->stacka;
	temp = hold->stacka;
	while (1)
	{
		while (temp->value < temp->next->value)
		{
			count++;
			temp = temp->next;
		}
		count++;
		if (count > *counthold)
		{
			*counthold = count;
			returnme = temp;
		}
		count = 0;
		temp = temp->next;
		if (temp == hold->stacka)
			break;
	}
	count = *counthold;
	while (--count)
		returnme = returnme->prev;
	return (returnme);
}

int algo1(t_table *hold)
{
	int		maxsortedcount;
	t_stack *startmaxsorted;
	t_stack *endmaxsorted;

	endmaxsorted = NULL;
	startmaxsorted = NULL;
	maxsortedcount = 0;
	presort(hold);
	startmaxsorted = check(hold, &maxsortedcount);
	endmaxsorted = startmaxsorted;
	while (--maxsortedcount > 0)
		endmaxsorted = endmaxsorted->next;
	if (startmaxsorted->prev == endmaxsorted)
		return (1);
	sortstart(hold, startmaxsorted->value, endmaxsorted->value);
	sortend(hold);
	return (0);
}

int sortstart(t_table *hold, int startend, int endend)
{
	int test;
	int pushed;

	startend++;
	pushed = 0;
	// endend = 21; for 100
	endend = 100;
	while (1)
	{
		pushrules(hold, 2);
		pushrules(hold, 2);
		if (hold->stackb->value < hold->stackb->next->value)
			swaprules(hold, 2);
		test = hold->stackb->value;
		while (pushed < endend && hold->stackamax)
		{
			while (hold->stacka->value < hold->stacka->next->value)
			{
				if (hold->stackbmax > 1)
					setupb(hold, hold->stacka->value, test);
				pushrules(hold, 2);
				if (hold->stackb->value > test)
					test = hold->stackb->value;
				pushed++;
			}
			// ft_printf("last one");
			if (hold->stackamax)
			{
				if (hold->stackbmax > 1)
					setupb(hold, hold->stacka->value, test);
				pushrules(hold, 2);
				if (hold->stackb->value > test)
					test = hold->stackb->value;
				pushed++;
			}
		}
		pushed = 0;
		while (hold->stackb->value < hold->stackb->prev->value)
			rrotaterules(hold, 2);
		if (!hold->stackamax)
			break;
	}
	return (0);
}