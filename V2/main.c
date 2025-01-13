/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 00:34:11 by ticasali          #+#    #+#             */
/*   Updated: 2025/01/13 16:21:06 by ticasali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int		main(int ac, char **av)
{
	int fd = open(av[1], O_RDONLY);
	int	check = 0;
	while (check != 10)
	{
		printf("RENDER -> %s\n",get_next_line(fd));
		check++;
	}
}