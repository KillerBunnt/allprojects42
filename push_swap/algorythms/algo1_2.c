#include "../includes/manditory.h"

t_stack *rotatesetup(t_stack *temp, int targetnum, int start, int end);
t_stack *rotatesetupa(t_stack *temp, int targetnum);

void setupb(t_table *hold, int targetnum, int start, int end)
{
	t_stack				*temp;
	unsigned int		pos;

	pos = 0;
	temp = hold->stackb;
	temp = rotatesetup(temp, targetnum, start, end);
	if (temp->prev->value > targetnum && temp->value < targetnum)
		pos = temp->position;
	else
	{
		temp = temp->next;
		temp = rotatesetup(temp, targetnum, start, end);
		pos = temp->position;
	}
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
	while (hold->stackbmax)
	{
		if (hold->stackamax > 1)
			setupa(hold, hold->stackb->value);
		// ft_printf("hi");
		pushrules(hold, 1);
	}
}

t_stack *rotatesetup(t_stack *temp, int targetnum, int start, int end)
{
	t_stack *temp2;

	temp2 = temp;
	while (temp->value < temp->prev->value)
	{
		if (start && end && temp->value == start)
		{
			while (temp->prev->value != end)
				temp = temp->next;
			if (temp == temp2)
				break;
		}
		if (temp->value < targetnum && temp->prev->value > targetnum)
			return (temp);
		temp = temp->next;
		if (temp == temp2)
			break;
	}
	return (temp);
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