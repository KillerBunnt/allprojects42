/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdexmund <tdexmund@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 15:45:35 by tdexmund          #+#    #+#             */
/*   Updated: 2024/09/26 15:45:35 by tdexmund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/manditory.h"

int	checkvalid(int argcount, char **args, t_table *hold)
{
	int	count;
	int	index;

	count = 0;
	index = 0;
	while (++index < argcount)
	{
		if (checkindex(args[index]))
		{
			ft_putstr_fd("Error\n", 2);
			freetable(hold);
			return (1);
		}
		while (++count < index)
		{
			if (ft_atoi(args[count]) == ft_atoi(args[index]))
			{
				ft_putstr_fd("Error\n", 2);
				freetable(hold);
				return (1);
			}
		}
		count = 0;
	}
	return (0);
}
