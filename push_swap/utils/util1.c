/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdexmund <tdexmund@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 15:45:35 by tdexmund          #+#    #+#             */
/*   Updated: 2024/09/26 15:45:35 by tdexmund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/manditory.h"

t_table	*inittable(void)
{
	t_table	*hold;

	hold = ft_calloc(1, sizeof(t_table));
	if (!hold)
		return (NULL);
	return (hold);
}

t_stack	*initstacks(int position, int value)
{
	t_stack	*stack;

	stack = ft_calloc(1, sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->position = position;
	stack->value = value;
	return (stack);
}

int	checkindex(const char *str1)
{
	int		temp;
	char	*str2;

	temp = ft_atoi(str1);
	str2 = ft_itoa(temp);
	if (!temp && ((ft_strlen(str1) > 1) || (str1[0] < '0' && str1[0] > '9')))
	{
		free(str2);
		return (1);
	}
	else if (!ft_strlen(str1) || ft_strncmp(str1, str2, ft_strlen(str1)))
	{
		free (str2);
		return (1);
	}
	free (str2);
	return (0);
}

int	checkargs(t_table *hold, int argcount, char **args)
{
	int		count;
	int		index;
	char	*temp;

	count = 0;
	index = 0;
	if (argcount == 2 && args[1][0])
	{
		temp = ft_strjoin("1 ", args[1]);
		args = ft_split((const char *)temp, ' ');
		argcount = 0;
		while (args[argcount])
			argcount++;
		free(temp);
	}
	if (checkvalid(argcount, args, hold))
		return (0);
	hold->stackamax = argcount - 1;
	hold->stackbmax = 0;
	if (!(fillstack(hold, argcount, args)))
	{
		freetable(hold);
		return (0);
	}
	return (1);
}

int	fillstack(t_table *hold, int argcount, char **args)
{
	t_stack	*temp;
	int		count;

	count = 0;
	hold->stacka = initstacks(--argcount, ft_atoi(args[++count]));
	if (!(hold->stacka))
		return (0);
	temp = hold->stacka;
	while (--argcount > 0)
	{
		hold->stacka->next = initstacks(argcount, ft_atoi(args[++count]));
		if (!(hold->stacka->next))
			return (0);
		hold->stacka->next->prev = hold->stacka;
		hold->stacka = hold->stacka->next;
	}
	temp->prev = hold->stacka;
	hold->stacka->next = temp;
	hold->stacka = hold->stacka->next;
	return (1);
}
