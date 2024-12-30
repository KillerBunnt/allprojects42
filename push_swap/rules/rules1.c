/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdexmund <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 13:32:29 by tdexmund          #+#    #+#             */
/*   Updated: 2024/12/30 13:32:30 by tdexmund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/manditory.h"

void	swapab(t_stack *curstack);
void	pusha(t_table *stacks);
void	pushb(t_table *stacks);

void	swaprules(t_table *stacks, int options)
{
	if (options == 1)
	{
		swapab(stacks->stacka);
		ft_printf("sa\n");
	}
	else if (options == 2)
	{
		swapab(stacks->stackb);
		ft_printf("sb\n");
	}
	else
	{
		swapab(stacks->stacka);
		swapab(stacks->stackb);
		ft_printf("ss\n");
	}
}

void	swapab(t_stack *curstack)
{
	int	temp;

	temp = curstack->value;
	curstack->value = curstack->next->value;
	curstack->next->value = temp;
}

void	pushrules(t_table *stacks, int options)
{
	if (options == 1)
	{
		if (stacks->stackbmax)
		{
			pusha(stacks);
			ft_printf("pa\n");
		}
		else
			return ;
	}
	else
	{
		if (stacks->stackamax)
		{
			pushb(stacks);
			ft_printf("pb\n");
		}
		else
			return ;
	}
}

void	pusha(t_table *stacks)
{
	t_stack	*temp;

	temp = stacks->stackb;
	if (stacks->stackbmax == 1)
		stacks->stackb = NULL;
	else
	{
		stacks->stackb->next->prev = stacks->stackb->prev;
		stacks->stackb->prev->next = stacks->stackb->next;
		stacks->stackb = stacks->stackb->next;
	}
	temp->next = temp;
	temp->prev = temp;
	if (stacks->stackamax)
	{
		temp->next = stacks->stacka;
		temp->prev = stacks->stacka->prev;
		stacks->stacka->prev->next = temp;
		stacks->stacka->prev = temp;
	}
	stacks->stacka = temp;
	(stacks->stackbmax)--;
	(stacks->stackamax)++;
	temp->position = stacks->stackamax;
}

void	pushb(t_table *stacks)
{
	t_stack	*temp;

	temp = stacks->stacka;
	if (stacks->stackamax == 1)
		stacks->stacka = NULL;
	else
	{
		stacks->stacka->next->prev = stacks->stacka->prev;
		stacks->stacka->prev->next = stacks->stacka->next;
		stacks->stacka = stacks->stacka->next;
	}
	temp->next = temp;
	temp->prev = temp;
	if (stacks->stackbmax)
	{
		temp->next = stacks->stackb;
		temp->prev = stacks->stackb->prev;
		stacks->stackb->prev->next = temp;
		stacks->stackb->prev = temp;
	}
	stacks->stackb = temp;
	(stacks->stackamax)--;
	(stacks->stackbmax)++;
	temp->position = stacks->stackbmax;
}
