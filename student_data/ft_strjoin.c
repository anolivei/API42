/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anolivei <anolivei@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/05 20:06:45 by anolivei          #+#    #+#             */
/*   Updated: 2020/07/14 12:50:16 by anolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "student_data.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char		*string;
	size_t		i;
	size_t		j;

	if (s1 == 0 || s2 == 0)
		return (0);
	i = 0;
	string = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (string == 0)
		return (0);
	while (s1[i] != '\0')
	{
		string[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		string[i] = s2[j];
		i++;
		j++;
	}
	string[i] = '\0';
	return (string);
}
