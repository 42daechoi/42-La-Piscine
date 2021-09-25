/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 16:19:15 by daechoi           #+#    #+#             */
/*   Updated: 2021/09/26 01:48:30 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_err_msg(void)
{
	write(2, "map error\n", 10);
}

void	ft_count_y_len(char *buff, t_mapinfo *mapinfo)
{
	int	i;

	i = 0;
	while (buff[i])
		i++;
	i -= (mapinfo->first_len);
	if (i % mapinfo->x_len != 0)
		ft_err_msg();
	else
		mapinfo->y_len = (i - mapinfo->x_len) / mapinfo->x_len;
}

void	ft_set_mapinfo(char *buff, t_mapinfo *mapinfo)
{
	mapinfo->x_len = buff[0] - 48;
	mapinfo->empty = buff[1];
	mapinfo->obstacle = buff[2];
	mapinfo->fill = buff[3];
}

void	ft_read_first_line(char *buff, t_mapinfo *mi)
{
	int	i;
	int	xlen;
	int	j;

	i = 0;
	xlen = 0;
	while (buff[i] != '\n')
		i++;
	if (i < 4)
	{
		ft_err_msg();
		return ;
	}
	mi->first_len = i + 1;
	mi->fill = buff[--i];
	mi->obstacle = buff[--i];
	mi->empty = buff[--i];
	j = 0;
	while (j < i)
		xlen = xlen * 10 + (buff[j++] - 48);
	mi->x_len = xlen;
}

int	main(int ac, char **av)
{
	int			fd;
	int			i;
	t_mapinfo	mapinfo;
	char		buff[BUFF_SIZE];
	ssize_t		rd_size;
	char		**arr;

	if (ac < 2)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	i = 1;
	while (i < ac)
	{
		fd = open(av[i], O_RDONLY);
		if (fd <= 0)
		{
			 write(2, "map error\n", 10);
			 break ;
		}
		rd_size = read(fd, buff, BUFF_SIZE - 1);
		if (rd_size > 0)
		{
			buff[rd_size] = '\0';
			ft_read_first_line(buff, &mapinfo);
			ft_count_y_len(buff, &mapinfo);
			arr = ft_do_malloc(arr, mapinfo);
			ft_set_map(buff, arr, mapinfo);
		//arr = ft_free(arr, mapinfo);
		}
		i++;
	}
	return (0);
}
