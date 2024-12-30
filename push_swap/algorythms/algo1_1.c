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

int	presortcheck(t_stack *stack)
{
	int		count;
	int		count2;
	t_stack	*temp;

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

void	presort(t_table *stacks)
{
	int	premoves;

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

int	algo1(t_table *hold)
{
	int		smallest;
	int		biggest;
	t_stack	*temp;

	temp = hold->stacka;
	while (temp->value < temp->next->value)
		temp = temp->next;
	if (temp == hold->stacka->prev)
		return (0);
	smallest = getsmallest(hold->stacka);
	biggest = getbiggest(hold->stacka);
	presort(hold);
	if (hold->stackamax <= 200)
		sortstart(hold, smallest, biggest, 10);
	else
		sortstart(hold, smallest, biggest, 20);
	sortend(hold);
	return (0);
}

int	sortstart(t_table *hold, int smallest, int biggest, int times)
{
	unsigned int	cursize;
	int				temp;
	int				chunksize;

	chunksize = (biggest - smallest) / times;
	cursize = 0;
	temp = times / 2;
	smallest += chunksize * temp;
	biggest -= chunksize * temp;
	while (temp--)
	{
		smallest -= chunksize;
		biggest += chunksize;
		process(hold, smallest, biggest, chunksize);
		process2(hold, smallest, biggest, chunksize);
	}
	return (0);
}
