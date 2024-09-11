/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdexmund <tdexmund@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 15:51:41 by tdexmund          #+#    #+#             */
/*   Updated: 2024/06/26 18:47:40 by tdexmund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	wordcount(char const *s, char c)
{
	int	count;
	int	count2;

	count2 = 0;
	count = 0;
	while (s[count])
	{
		while (s[count] && s[count] == c)
			count++;
		if (s[count])
			count2++;
		while (s[count] && s[count] != c)
			count++;
	}
	return (count2);
}

static char	*alloc(char const *s, char c, int count2)
{
	int		count;
	char	*temp;

	count = 0;
	while (s[count2] && s[count2] != c)
	{
		count++;
		count2++;
	}
	temp = (char *)malloc(count + 1 * sizeof(char));
	if (!temp)
		return (0);
	return (temp);
}

static int	wordfill(char **temp, char const *s, char c, int count3)
{
	int	count;
	int	count2;

	count2 = 0;
	count = 0;
	while (s[count])
	{
		while (s[count] && s[count] == c)
			count++;
		if (s[count])
		{
			temp[count2] = alloc(s, c, count);
			if (!temp[count2])
				return (-1);
		}
		while (s[count] && s[count] != c)
			temp[count2][++count3] = s[count++];
		if (!s[count] && s[count - 1] == c)
			break ;
		temp[count2][++count3] = 0;
		count3 = -1;
		count2++;
	}
	temp[count2] = 0;
	return (0);
}

char	**ft_split(char const *s, char c)
{
	int		count;
	char	**temp;

	count = wordcount(s, c);
	temp = (char **)malloc((count + 1) * sizeof(char *));
	if (!temp)
		return (0);
	if (count == 0)
	{
		temp[0] = 0;
		return (temp);
	}
	if (wordfill(temp, s, c, -1) == -1)
		return (0);
	return (temp);
}
