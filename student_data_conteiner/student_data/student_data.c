/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   student_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anolivei <anolivei@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 00:30:19 by anolivei          #+#    #+#             */
/*   Updated: 2020/07/15 20:18:41 by anolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "student_data.h"

/*
** Funcao que cria o token e o salva em um arquivo txt
*/

int		create_token(void)
{
	char		*uid_secret;
	FILE		*file;
	CURL		*curl;
	CURLcode	res;

	printf("\nGerando token...\n");
	file = fopen("token.txt", "wb");
	uid_secret = ft_strjoin("grant_type=client_credentials&client_id=", UID);
	uid_secret = ft_strjoin(uid_secret, "&client_secret=");
	uid_secret = ft_strjoin(uid_secret, SECRET);
	curl = curl_easy_init();
	if (curl)
	{
		curl_easy_setopt(curl, CURLOPT_URL, "https://api.intra.42.fr/oauth/token");
		curl_easy_setopt(curl, CURLOPT_POSTFIELDS, uid_secret);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, file);
		res = curl_easy_perform(curl);
		curl_easy_cleanup(curl);
	}
	fclose(file);
	return (0);
}

/*
** Funcao que adquire os dados e os salva em um arquivo txt
*/

int		get_data(char *user)
{
	FILE		*file;
	char		*string1;
	char		*string2;
	char		*call_token;
	char		*url_api;
	CURL		*curl;
	CURLcode	res;

	printf("\nBaixando dados...\n");
	file = fopen("data.txt", "wb");
	string1 = "Authorization: Bearer ";
	string2 = read_token();
	call_token = ft_strjoin(string1, string2);
	string1 = API;
	string2 = user;
	url_api = ft_strjoin(string1, string2);
	curl = curl_easy_init();
	if (curl)
	{
		struct curl_slist *chunk = NULL;
		chunk = curl_slist_append(chunk, call_token);
		curl_easy_setopt(curl, CURLOPT_URL, url_api);
		curl_easy_setopt(curl, CURLOPT_HTTPHEADER, chunk);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, file);
		res = curl_easy_perform(curl);
		curl_easy_cleanup(curl);
	}
	fclose(file);
	return (0);
}

/*
** Funcao que aloca os dados do arquivo txt em uma variavel
*/

char	*allocate_data(void)
{
	int		fd;
	char	*data;
	int		i;
	int		j;
	char	c;

	j = file_len();
	data = malloc(sizeof(char) * j + 1);
	fd = open("data.txt", O_RDONLY);
	i = 0;
	while (i < j)
	{
		read(fd, &c, 1);
		data[i] = c;
		i++;
	}
	return (&data[0]);
}

/*
** Funcao que aloca o token em uma variavel
*/

char	*read_token(void)
{
	int		fd;
	int		i;
	char	c;
	char	*token;

	if ((token = malloc(sizeof(char) * 81)) == 0)
		return ("error");
	fd = open("token.txt", O_RDONLY);
	if (fd == -1)
		return ("error");
	i = 0;
	while (i < 81)
	{
		read(fd, &c, 1);
		token[i] = c;
		i++;
	}
	token[81] = '\0';
	close(fd);
	return (&token[17]);
}

/*
** Funcao que retorna a quantidade de caracteres dentro de um txt para o malloc
*/

int		file_len(void)
{
	FILE	*fp;
	int		count;
	char	c;

	c = 0;
	count = 0;
	fp = fopen("data.txt", "r");
	if (fp == NULL)
		return (0);
	for (c = getc(fp); c != EOF; c = getc(fp))
	{
		count = count + 1;
	}
	fclose(fp);
	return (count);
}
