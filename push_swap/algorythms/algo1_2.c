#include "../includes/manditory.h"

t_stack *rotatesetupb(t_stack *temp, int targetnum);
t_stack *rotatesetupa(t_stack *temp, int targetnum);

void setupb(t_table *hold, int targetnum, int end)
{
	t_stack				*temp;
	unsigned int		pos;

	pos = 0;
	temp = hold->stackb;
	while (temp->value != end)
		temp = temp->prev;
	temp = rotatesetupb(temp, targetnum);
	pos = temp->position;
	// ft_printf("(%d, %d, %d, %d)", end, temp->value, temp->position, targetnum);
	if (hold->stackb->position - pos < pos)
		while (++pos <= hold->stackbmax)
			rotaterules(hold, 2);
	else if (pos)
		while(1)
		{
			rrotaterules(hold, 2);
			if (!(--pos))
				break;
		}
}

void setupa(t_table *hold, int targetnum)
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
		while(1)
		{
			rrotaterules(hold, 1);
			if (!(--pos))
				break;
		}
}

void sortend(t_table *hold)
{
	t_stack *temp;

	while (hold->stackbmax)
	{
		if (hold->stackamax > 1)
			setupa(hold, hold->stackb->value);
		pushrules(hold, 1);
	}
	temp = hold->stacka;
	while (temp->value > temp->prev->value)
		temp = temp->prev;
	if (hold->stackamax - temp->position < (unsigned int)temp->position)
		while (hold->stacka->value > hold->stacka->prev->value)
			rotaterules(hold, 1);
	else
		while (hold->stacka->value > hold->stacka->prev->value)
			rrotaterules(hold, 1);
}

t_stack *rotatesetupb(t_stack *temp, int targetnum)
{
	t_stack *first;

	first = temp;
	while (temp->value > temp->next->value)
	{
		if (temp->value < targetnum && temp->prev->value > targetnum)
			return (temp);
		temp = temp->next;
	}
	if (temp->value < targetnum && temp->prev->value > targetnum)
		return (temp);
	if (targetnum < temp->value)
		return (temp->next);
	return (first);
}

t_stack *rotatesetupa(t_stack *temp, int targetnum)
{
	while (temp->value > temp->prev->value)
	{
		if (temp->value > targetnum && temp->prev->value < targetnum)
			return (temp);
		temp = temp->next;
	}
	return (temp);
}