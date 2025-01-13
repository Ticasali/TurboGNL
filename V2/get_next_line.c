/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 09:31:58 by ticasali          #+#    #+#             */
/*   Updated: 2025/01/13 17:25:44 by ticasali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	New->str = str;
	New->ct = lenght;
	New->check = check;
	New->next = NULL;
	lst->next = New;
	return (true);
}

size_t	concatlen(Line_t *lst)
{
	Line_t	*Cpy;
	size_t	ct;

	Cpy = lst;
	ct = 0;
	while (Cpy != NULL)
	{
		ct += Cpy->ct;
		if (Cpy->check == true)
			return (ct);
		Cpy = Cpy->next;
	}
	return (ct);
}

char	*ft_concat(Line_t *lst)
{
	size_t	ct;
	size_t	ct_f;
	char	*ret;

	ct = 0;
	ct_f = 0;
	ret = malloc(sizeof(char) * concatlen(lst) + 1);
	if (ret == NULL)
		return (NULL);
	while (lst != NULL)
	{
		while (lst->str[ct] != '\0')
		{
			ret[ct_f] = lst->str[ct];
			++ct;
			++ct_f;
		}
		ct = 0;
		if (lst->check == true)
			break;
		lst = lst->next;
	}
	ret[ct_f] = '\0';
	return (ret);
}

char	*get_next_line(int fd)
{
	char	temp[BUFFER_SIZE];
	static	Line_t	*lst;
	Line_t	*Cpy;
	size_t	ct;
	size_t	save;
	bool	check;
	bool	Turbocheck = false;
	char	*ret;

	ct = 0;
	save = 0;
	check = false;
	if (fd < 0)
		return (NULL);
	while (ct < BUFFER_SIZE)
	{
		if (ct == 0)
			if (read(fd, temp, BUFFER_SIZE) == 0)
				break;
		if (temp[ct] == '\n')
		{
			if (lst == NULL)
			{
				lst = malloc(sizeof(Line_t));
				lst->str = turbo_str_copy_dup(&temp[save], ct - save + 1);
				if (lst->str == NULL)
					return (NULL);
				lst->ct = ct - save + 1;
				lst->check = true;
				lst->next = NULL;
			}
			else if (add_back(lst, turbo_str_copy_dup(&temp[save], ct - save + 1), ct - save + 1, true) == false)
				return (free_all(lst));
			save = ct + 1;
			check = true;
		}
		++ct;
		if (ct == BUFFER_SIZE && check == false)
		{
			if (lst == NULL)
			{
				lst = malloc(sizeof(Line_t));
				lst->str = turbo_str_copy_dup(&temp[save], ct - save + 1);
				if (lst->str == NULL)
					return (NULL);
				lst->ct = ct - save + 1;
				lst->check = false;
				lst->next = NULL;
			}
			else if (add_back(lst, turbo_str_copy_dup(&temp[save], ct - save), ct - save, false) == false)
				return (free_all(lst));
			ct = 0;
			save = 0;
		}
	}
	if (ct == BUFFER_SIZE && check == true)
		if (add_back(lst, turbo_str_copy_dup(&temp[save], ct - save), ct - save, false) == false)
			return (free_all(lst));
	ret = ft_concat(lst);
	while (lst->check != true && lst->next != NULL)
	{
		Cpy = lst;
		lst = lst->next;
		printf("-->%s\n", Cpy->str);
		printf("-->%lu\n", Cpy->ct);
		free(Cpy->str);
		free(Cpy);
	}
	Cpy = lst;
	lst = lst->next;
	printf("-->%s\n", Cpy->str);
	printf("-->%lu\n", Cpy->ct);
	free(Cpy->str);
	free(Cpy);
	return (ret);
}