/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   student_data.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anolivei <anolivei@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 12:50:33 by anolivei          #+#    #+#             */
/*   Updated: 2020/09/01 14:39:30 by anolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STUDENT_DATA_H
# define STUDENT_DATA_H

/*
** Includes
*/

# include <curl/curl.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>

/*
** Defines
*/

# define UID	"digite aqui seu UID"
# define SECRET	"digite aqui seu SECRET"
# define API	"https://api.intra.42.fr/v2/users/"

/*
** Funcoes student_data
*/

int		verify_token(void);
char	*allocate_data(void);
int		get_data(char *user);
int		create_token(void);
int		put_token(void);
char	*read_token(void);
int		file_len(void);
int		split_json(void);
int		str_first_position(char *data, char *flag);
int		return_flags(char *flag);
int		main(int argc, char *argv[]);

/*
** Funcoes Lib
*/

char	*ft_strjoin(char *s1, char *s2);
int		ft_strchr(char *s, int c);
int		ft_strlen(const char *str);

#endif
