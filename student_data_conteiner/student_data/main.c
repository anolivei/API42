/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anolivei <anolivei@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 17:41:57 by anolivei          #+#    #+#             */
/*   Updated: 2020/07/15 20:23:24 by anolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "student_data.h"

/*
** Main, para coordenar as funcoes
*/
int	main(int argc, char *argv[])
{
	int		len;

	len = 0;
	if (argc != 2 && argc != 3)
	{
		printf("ERRO: Digite um ou dois argumentos\n");
		return (0);
	}
	get_data(argv[1]);
	len = file_len();
	if (len < 80 && len != 2)
	{
		create_token();
		get_data(argv[1]);
		len = file_len();
	}
	if (len == 2)
	{
		printf("ERRO: Usuário inválido\n");
		return (0);
	}
	argc == 3 ? return_flags(argv[2]) : split_json();
	return (0);
}
