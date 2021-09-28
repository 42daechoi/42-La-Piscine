/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cnt_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 23:26:14 by daechoi           #+#    #+#             */
/*   Updated: 2021/09/26 23:32:49 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "header.h"

int	ft_cnt_file(char **av, int *cnt, int i)
{
	int		fd;
	char	c;

	fd = open(av[i], O_RDONLY);
	if (fd <= 0)
	{
		ft_err_msg();
		return (0);
	}
	while (read(fd, &c, 1) != '\0')
		(*cnt)++;
	close(fd);
	return (1);
}
