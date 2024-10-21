/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdexmund <tdexmund@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 15:45:31 by tdexmund          #+#    #+#             */
/*   Updated: 2024/09/26 15:45:31 by tdexmund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/manditory.h"

t_table	*inittable();

int main(int argcount, char **args)
{
	t_table *hold;

	hold = NULL;
	if (argcount == 1)
		return (0);
	hold = inittable();
	if (checkargs(hold, argcount, args) == 0)
		return (0);
	//algo start here
	algo1(hold);
	//bottom is testing
	// int count = 0;
	// while (++count < 4)
	// 	pushrules(hold, 0);
	// rotaterules(hold, -1);
	//bottom is show
	// t_stack *temp = hold->stacka;
	// ft_printf("--------\nA\n--------\n");
	// if (!temp)
	// 	ft_printf("NULL  NULL\n");
	// else
	// 	do
	// 	{
	// 		ft_printf("%d  %d\n", temp->value, temp->position);
	// 		temp = temp->next;
	// 	}while (temp != hold->stacka);
	
	// ft_printf("--------\nB\n--------\n");
	// temp = hold->stackb;
	// if (!temp)
	// 	ft_printf("NULL  NULL\n");
	// else
	// 	do
	// 	{
	// 		ft_printf("%d  %d\n", temp->value, temp->position);
	// 		temp = temp->next;
	// 	}while (temp != hold->stackb);
	freetable(hold);
}