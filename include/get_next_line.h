/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 12:51:31 by ticasali          #+#    #+#             */
/*   Updated: 2025/01/08 13:36:03 by ticasali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	GET_NEXT_LINE_H
#define GET_NEXT_LINE_H
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

#ifndef	BUFFER_SIZE
#define BUFFER_SIZE 4096
#endif

typedef struct	line_s
{
	char	*str;
	size_t	ct;
	struct line_s *next;
}Line_t;

#endif