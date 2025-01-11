/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 12:59:09 by ticasali          #+#    #+#             */
/*   Updated: 2025/01/11 02:38:24 by ticasali         ###   ########.fr       */
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

void	ft_strcat(Line_t	*lst, char *str)
{
	char	*ret;
	size_t	ct_f;
	size_t	ct;

	ct = 0;
	ct_f = 0;
	while (str[lst->ct] != '\0')
		++lst->ct;
	ret = malloc(sizeof(char) * lst->ct + 1);
	while (lst->str[ct] != '\0')
	{
		ret[ct] = lst->str[ct];
		++ct;
		++ct_f;
	}
	free(lst->str);
	ct = 0;
	while (str[ct] != '\0')
	{
		ret[ct_f] = str[ct];
		++ct;
		++ct_f;
	}
	ret[ct_f] = '\0';
	lst->str = ret;
}

bool	add_back(Line_t	*lst, char *str, size_t lenght, bool check)
{
	Line_t	*New;
	while (lst->next != NULL)
		lst = lst->next;
	if (lst != NULL && check == false && lst->check == false)
		ft_strcat(lst, str);
	else if (lst != NULL && lst->check == false && check == true)
	{
		ft_strcat(lst, str);
		lst->check = true;
	}
	else
	{
		New = malloc(sizeof(Line_t));
		if (New == NULL || str == NULL)
			return (false);
		New->str = str;
		New->ct = lenght;
		New->check = check;
		New->next = NULL;
		if (lst != NULL)
			lst->next = New;
		else
			lst = New;
	}
	return (true);
}

char	*get_next_line(int fd)
{
	char	temp[BUFFER_SIZE];
	size_t		ct;
	size_t		save;
	static	Line_t *lst;
	Line_t		*Cpy;

	ct = 0;
	save = 0;
	if (lst != NULL && lst->check == true)
	{
		Cpy = lst;
		lst = lst->next;
//		return ()
		free(Cpy);
	}
	if (lst == NULL)
	{
		lst = malloc(sizeof(Line_t));
		lst->ct = 1;
		lst->str = malloc(sizeof(char) * 2);
		lst->str[0] = 'T';
		lst->str[1] = '\0';
		lst->check = true;
		lst->next = NULL;
	}
	if (fd < 0)
		return (NULL);
	read(fd, temp, BUFFER_SIZE);
	while (ct < BUFFER_SIZE && temp[ct] != '\0')
	{
		if (temp[ct] == '\n')
		{
			if (add_back(lst, turbo_str_copy_dup(&temp[save], ct - save), ct - save, true) == false)
				return (free_all(lst));
			save = ct;
		}
		++ct;
	}
	if (temp[ct - 1] != '\n' && temp[ct - 1] != '\0')
		if (add_back(lst, turbo_str_copy_dup(&temp[save], ct - save), ct - save, false) == false)
			return (free_all(lst));
	if (temp[ct - 1] == '\n' || temp[ct - 1] == '\0')
		if (add_back(lst, turbo_str_copy_dup(&temp[save], ct - save), ct - save, true) == false)
			return (free_all(lst));
	if (lst->check == true)
		return (lst->str);
	return (NULL);
}