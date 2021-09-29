/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cnt_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 23:26:14 by daechoi           #+#    #+#             */
/*   Updated: 2021/09/29 19:10:32 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "header.h"

int	ft_cnt_file(char **av, int *cnt, int i)
{
	int		fd;
	char	c;

	fd = open(av[i], O_RDONLY);
	if (fd < 0)
	{
		ft_err_msg();
		return (0);
	}
	while (read(fd, &c, 1) != '\0')
		(*cnt)++;
	close(fd);
	return (1);
}

int	ft_cnt_y(char *buff, int *cnt, t_mapinfo *mi)
{
	int	now_len;
	int	j;

	j = mi->first_len;
	now_len = 0;
	while (buff[j])
	{
		if (buff[j] == '\n' || buff[j] == '\0')
		{
			now_len = (j - (mi->first_len - 1)) / ++(*cnt);
			if ((j - (mi->first_len - 1)) % *cnt != 0)
			{
				ft_err_msg();
				return (0);
			}
			if (now_len != mi->y_len + 1 || *cnt == 0)
			{
				ft_err_msg();
				return (0);
			}
		}
		j++;
	}
	return (1);
}

void	ft_open_file(char **av, int cnt, int i)
{
	int	fd;

	fd = open(av[i], O_RDONLY);
	ft_file_read(fd, cnt);
	close(fd);
}
