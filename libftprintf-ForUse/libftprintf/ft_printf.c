/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdexmund <tdexmund@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 14:44:18 by tdexmund          #+#    #+#             */
/*   Updated: 2024/07/23 14:44:18 by tdexmund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	perccheck(const char form, va_list args)
{
	int	countme;

	countme = 0;
	if (form == 'c')
		countme = ft_putchar_fd(va_arg(args, int), 1);
	else if (form == 's')
		countme = ft_putstr_fd(va_arg(args, char *), 1);
	else if (form == 'p')
		countme = print_p(va_arg(args, void *));
	else if (form == 'd' || form == 'i')
		countme = ft_putnbr_fd(va_arg(args, int), 1);
	else if (form == 'u')
		print_u(va_arg(args, unsigned int), &countme);
	else if (form == 'x' || form == 'X')
		countme = print_x(va_arg(args, int), form);
	else if (form == '%')
		countme = ft_putchar_fd('%', 1);
	return (countme);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		strcount;
	int		countall;

	countall = 0;
	strcount = -1;
	va_start(args, str);
	while (str[++strcount])
	{
		if (str[strcount] == '%')
			countall += perccheck(str[++strcount], args);
		else
		{
			write(1, &(str[strcount]), 1);
			countall++;
		}
	}
	va_end(args);
	return (countall);
}
