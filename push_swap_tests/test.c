#include "includes/manditory.h" 
#include "rules/rules1.c"
#include "rules/rules2.c"

void	*ft_calloc(size_t count, size_t size)
{
	char			*temp;
	size_t			count2;

	count2 = 0;
	temp = malloc(count * size);
	if (temp == 0)
		return (0);
	while (count2 < count * size)
	{
		temp[count2] = 0;
		count2++;
	}
	return ((void *)temp);
}

#include <stdio.h>
#include <unistd.h>
int main()
{
	t_table *new;
	t_stack *first;
	int count = 4;
	new = ft_calloc(1, sizeof(t_table));
	new->stacka = ft_calloc(1, sizeof(t_stack));
	first = new->stacka;
	new->stacka->value = count;
	new->stacka->position = 4;
	while (--count > 0)
	{
		new->stacka->next = ft_calloc(1, sizeof(t_stack));
		new->stacka->next->prev = new->stacka;
		new->stacka = new->stacka->next;
		new->stacka->value = count;
		new->stacka->position = count;
	}
	new->stacka->next = first;
	first->prev = new->stacka;
	new->stacka = first;
	new->stackamax = 4;
	rotaterules(new, -1);
	while (++count < 5)
	{
		printf("| %d %d | ", new->stacka->value, new->stacka->position);
		new->stacka = new->stacka->next;
	}
		while (++count < 5)
	{
		printf("| %d %d | ", new->stacka->value, new->stacka->position);
		new->stacka = new->stacka->next;
	}
}