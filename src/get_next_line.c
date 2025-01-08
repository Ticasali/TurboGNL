/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 12:59:09 by ticasali          #+#    #+#             */
/*   Updated: 2025/01/08 13:46:34 by ticasali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line.h"

char	*

char	*get_next_line(int fd)
{
	char	temp[BUFFER_SIZE];
	int		ct;
	int		save;
	size_t	count;
	static	Line_t *lst;

	ct = 0;
	save = 0;
	lst = malloc(sizeof(Line_t));
	if (!lst)
		//
	if (fd < 0)
		return (NULL);
	count = read(fd, temp, BUFFER_SIZE);
	while (ct < BUFFER_SIZE && temp[ct] != '\0')
	{
		++ct;
		if (temp[ct] == '\n')
		{
			add_back(lst, turbo_str_copy_dup(&temp[save], ct, save));
			save = ct;
		}
	}
}