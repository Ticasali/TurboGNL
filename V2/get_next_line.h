/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 09:32:07 by ticasali          #+#    #+#             */
/*   Updated: 2025/01/13 17:22:22 by ticasali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	GET_NEXT_LINE_H
#define GET_NEXT_LINE_H
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdio.h>

#ifndef	BUFFER_SIZE
#define BUFFER_SIZE 4096
#endif

typedef struct	line_s
{
	char	*str;
	size_t	ct;
	bool	check;
	struct line_s *next;
}Line_t;

char	*get_next_line(int fd);
char	*turbo_str_copy_dup(char *cpy, size_t lenght);
char	*ft_concat(Line_t *lst);
void	*free_all(Line_t *lst);
size_t	concatlen(Line_t *lst);
bool	add_back(Line_t	*lst, char *str, size_t lenght, bool check);

#endif