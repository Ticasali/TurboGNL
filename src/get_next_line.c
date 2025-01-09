/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 12:59:09 by ticasali          #+#    #+#             */
/*   Updated: 2025/01/09 16:21:08 by ticasali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line.h"

char	*turbo_str_copy_dup(char *cpy, size_t lenght)
{
	size_t	ct;
	char	*ret;

	ct = 0;
	ret = malloc(sizeof(char) * lenght + 1);
	if (ret == NULL)
		return (NULL);
	while (ct < lenght)
	{
		ret[ct] = cpy[ct];
		++ct;
	}
	ret[ct] = '\0';
	return (ret);
}

void	*free_all(Line_t *lst)
{
	Line_t	*Cpy;
	while (lst != NULL)
	{
		Cpy = lst;
		free(Cpy->str);
		free(Cpy);
		lst = lst->next;
	}
	return (NULL);
}

bool	add_back(Line_t	*lst, char *str, size_t lenght, bool check)
{
	Line_t	*New;
	while (lst->next != NULL)
		lst = lst->next;
	New = malloc(sizeof(Line_t));
	if (New == NULL || str == NULL)
		return (false);
//	if (lst != NULL && check == false)
	New->str = str;
	New->ct = lenght;
	New->check = check;
	New->next = NULL;
	if (lst != NULL)
		lst->next = New;
	else
		lst = New;
	return (true);
}

char	*get_next_line(int fd)
{
	char	temp[BUFFER_SIZE];
	size_t		ct;
	size_t		save;
	static	Line_t *lst;

	ct = 0;
	save = 0;
	lst = malloc(sizeof(Line_t));
	if (fd < 0)
		return (NULL);
	read(fd, temp, BUFFER_SIZE);
	while (ct < BUFFER_SIZE && temp[ct] != '\0')
	{
		++ct;
		if (temp[ct] == '\n')
		{
			if (add_back(lst, turbo_str_copy_dup(&temp[save], ct - save), ct - save, true) == false)
				return (free_all(lst));
			save = ct;
		}
	}
	if (temp[ct] != '\n' && temp[ct] != '\0')
		if (add_back(lst, turbo_str_copy_dup(&temp[save], ct - save), ct - save, false) == false)
			return (free_all(lst));
	
}