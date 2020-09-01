/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   student_data_layout.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anolivei <anolivei@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 17:48:39 by anolivei          #+#    #+#             */
/*   Updated: 2020/07/15 20:10:38 by anolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "student_data.h"

/*
** Funcao para formatacoes basicas do json
*/
int	split_json(void)
{
	char	*data;
	int		i;

	data = allocate_data();
	i = 0;
	while (data[i] != '\0')
	{
		if (data[i] == ',' || data[i] == '}' || data[i] == '{')
			data[i] = '\n';
		if (data[i] == '"' || data[i] == ']' || data[i] == '[')
			data[i] = ' ';
		i++;
	}
	printf("\n%s\n", data);
	return (0);
}

/*
** Funcao que procura a primeira posicao de uma string
*/
int	str_first_position(char *data, char *flag)
{
	char *p;

	p = strstr(data, flag);
	if (p)
		return (p - data);
	return (0);
}

/*
** Funcao para leitura de flags no segundo argumento
*/
int	return_flags(char *flag)
{
	int		i;
	char	*data;

	data = allocate_data();
	i = 0;
	if ((i = str_first_position(data, flag)) != 0)
	{
		while (data[i] != ',')
		{
			if (data[i] != '"')
				printf("%c", data[i]);
			i++;
		}
		printf("\n");
		return (1);
	}
	else
		printf("Flag não encontrada\n");
	return (0);
}
