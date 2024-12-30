/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdexmund <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 13:32:33 by tdexmund          #+#    #+#             */
/*   Updated: 2024/12/30 13:32:34 by tdexmund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/manditory.h"

void	rotateab(t_stack *curstack);
void	rrotateab(t_stack *curstack);

void	rrotaterules(t_table *stacks, int options)
{
	if (options == 1)
	{
		rrotateab(stacks->stacka);
		stacks->stacka = stacks->stacka->prev;
		ft_printf("rra\n");
	}
	else if (options == 2)
	{
		rrotateab(stacks->stackb);
		stacks->stackb = stacks->stackb->prev;
		ft_printf("rrb\n");
	}
	else if (options == 3)
	{
		rrotateab(stacks->stacka);
		stacks->stacka = stacks->stacka->prev;
		rrotateab(stacks->stackb);
		stacks->stackb = stacks->stackb->prev;
		ft_printf("rrr\n");
	}
}

void	rotaterules(t_table *stacks, int options)
{
	if (options == 1)
	{
		rotateab(stacks->stacka);
		stacks->stacka = stacks->stacka->next;
		ft_printf("ra\n");
	}
	else if (options == 2)
	{
		rotateab(stacks->stackb);
		stacks->stackb = stacks->stackb->next;
		ft_printf("rb\n");
	}
	else if (options == 3)
	{
		rotateab(stacks->stacka);
		stacks->stacka = stacks->stacka->next;
		rotateab(stacks->stackb);
		stacks->stackb = stacks->stackb->next;
		ft_printf("rr\n");
	}
}

void	rotateab(t_stack *curstack)
{
	int	temp;

	temp = curstack->position;
	while (curstack->position != temp + 1)
	{
		(curstack->position)++;
		curstack = curstack->next;
	}
	curstack->position = 1;
}

void	rrotateab(t_stack *curstack)
{
	int	temp;

	temp = curstack->position;
	curstack = curstack->prev;
	while (curstack->position != 0)
	{
		(curstack->position)--;
		curstack = curstack->prev;
	}
	curstack->position = temp;
}
