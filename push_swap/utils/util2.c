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

int getsmallestsorted(t_stack *hold)
{
	int size;
	int cursize;

	cursize = 0;
	size = 0;
	while (hold->position != 1)
	{
		cursize++;
		if (hold->value > hold->next->value)
		{
			if (size == 0 || cursize < size)
				size = cursize;
			cursize = 0;
		}
		hold = hold->next;
	}
	return (size);
}