/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manditory.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdexmund <tdexmund@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 13:59:59 by tdexmund          #+#    #+#             */
/*   Updated: 2024/09/24 13:59:59 by tdexmund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MANDITORY_H
# define MANDITORY_H

# include <unistd.h>
# include <stdlib.h>
# include "../libftprintf/ft_printf.h"
# include "../libftprintf/libft/libft.h"

typedef struct s_stack	t_stack;

typedef struct s_stack{
	int		position;
	int		value;
	t_stack	*next;
	t_stack	*prev;
}	t_stack;

typedef struct s_table{
	t_stack			*stacka;
	t_stack			*stackb;
	unsigned int	stackamax;
	unsigned int	stackbmax;
}	t_table;

void	rotaterules(t_table *stacks, int options);
void	rrotaterules(t_table *stacks, int options);
void	swaprules(t_table *stacks, int options);
void	pushrules(t_table *stacks, int options);
void	*ft_calloc(size_t count, size_t size);
t_table	*inittable(void);
t_stack	*initstacks(int position, int value);
void	freetable(t_table *hold);
void	freestack(t_stack *hold, int stackmax);
int		fillstack(t_table *hold, int argcount, char **args);
int		checkargs(t_table *hold, int argcount, char **args);
int		algo1(t_table *hold);
// int		algo2(t_table *hold);
t_stack	*check(t_table *hold, int *counthold);
void	presort(t_table *stacks);
void	setupa(t_table *hold, int targetnum);
void	setupb(t_table *hold, int targetnum);
int		sortstart(t_table *hold, int smallest, int biggest, int chunksize);
void	sortend(t_table *hold);
int		getsmallest(t_stack *hold);
int		getbiggest(t_stack *hold);
t_stack	*skippart(int start, int end, t_stack *temp, int targetnum);
t_stack	*getcorrectpos(t_stack *temp, int end, int start, int targetnum);
void	reset(t_table *hold, unsigned int pos, int mode);
void	process(t_table *hold, int smallest, int biggest, int chunksize);
void	process2(t_table *hold, int smallest, int biggest, int chunksize);
void	flushb(t_table *hold);
void	rotatecorrect(t_table *hold);
int		checkvalid(int argcount, char **args, t_table *hold);
void	startsimplesort(t_table *hold);
int		checkindex(const char *str1);

#endif