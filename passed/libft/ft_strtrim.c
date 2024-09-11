/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdexmund <tdexmund@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 16:19:13 by tdexmund          #+#    #+#             */
/*   Updated: 2024/06/30 14:36:41 by tdexmund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	countb(char const *s1, char const *set, int count1)
{
	int		count3;

	while (s1[count1 + 1])
		count1++;
	count3 = -1;
	while (set[++count3])
	{
		if (s1[count1] == set[count3])
		{
			count1--;
			count3 = -1;
		}
	}
	return (count1);
}

static int	countf(char const *s1, char const *set)
{
	int		count1;
	int		count3;

	count3 = -1;
	count1 = 0;
	while (set[++count3])
	{
		if (s1[count1] == set[count3])
		{
			count1++;
			count3 = -1;
		}
	}
	return (count1);
}

static void	fill(char *temp, char const *s1, int start, int end)
{
	int	count;

	count = -1;
	while (start <= end)
	{
		temp[++count] = s1[start];
		start++;
	}
	temp[++count] = 0;
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*temp;

	if (s1[0] == '\0')
		return (ft_strdup(""));
	start = countf(s1, set);
	end = countb(s1, set, 0);
	if (start > end)
	{
		temp = (char *)malloc(1 * sizeof(char));
		if (!temp)
			return (0);
		temp[0] = 0;
		return (temp);
	}
	temp = (char *)malloc((end - start + 2) * sizeof(char));
	if (temp == 0)
		return (0);
	fill(temp, s1, start, end);
	if (temp[0] == 0)
		return (0);
	return (temp);
}
