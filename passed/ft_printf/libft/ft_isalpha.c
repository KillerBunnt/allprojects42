/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdexmund <tdexmund@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 13:00:11 by tdexmund          #+#    #+#             */
/*   Updated: 2024/06/24 15:54:53 by tdexmund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}
/*
#include <ctype.h>
#include <stdio.h>
int main(){
 	int i;

 	i = -1;
 	while (i < 530)
 	{
 		if (!!ft_isalpha(i) != !!isalpha(i))
 			printf("fail");
 		i++;
 	}
 	printf("pass");
}*/
