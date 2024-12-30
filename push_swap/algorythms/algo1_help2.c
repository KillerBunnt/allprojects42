/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo1_help2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdexmund <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 13:20:28 by tdexmund          #+#    #+#             */
/*   Updated: 2024/12/30 13:20:29 by tdexmund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/manditory.h"

void	process2(t_table *hold, int smallest, int biggest, int chunksize)
{
	if (hold->stacka)
	{
		if (hold->stacka->value >= smallest
			&& hold->stacka->value <= biggest)
		{
			pushrules(hold, 2);
			if (hold->stackb->value <= smallest + chunksize)
				rotaterules(hold, 2);
		}
		else
			rotaterules(hold, 1);
	}
}
