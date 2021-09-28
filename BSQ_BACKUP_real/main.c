/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 16:19:15 by daechoi           #+#    #+#             */
/*   Updated: 2021/09/28 21:26:24 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_err_msg(void)
{
	write(2, "map error\n", 10);
}

int	ft_count_y_len(char *buff, t_mapinfo *mi)
{
	int	i;
	int	j;
	int	cnt;
	int	now_len;

	i = 0;
	while (buff[i])
		i++;
	mi->y_len = (i - mi->first_len - mi->x_len) / mi->x_len;
	j = mi->first_len;
	cnt = 0;
	while (buff[j])
	{
		if (buff[j] == '\n')
		{
			now_len = (j - (mi->first_len - 1)) / ++cnt;
			if (now_len != mi->y_len + 1 || cnt == 0)
			{
				ft_err_msg();
				return (0);
			}
		}
		j++;
	}
	if (cnt != mi->x_len)
	{
		ft_err_msg();
		return (0);
	}
	return (1);
}

int	ft_read_first_line(char *buff, t_mapinfo *mi)
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
		return (0);
	}
	mi->first_len = i + 1;
	mi->fill = buff[--i];
	mi->obstacle = buff[--i];
	mi->empty = buff[--i];
	j = 0;
	while (j < i)
		xlen = xlen * 10 + (buff[j++] - 48);
	mi->x_len = xlen;
	return (1);
}

int	ft_file_read(int fd, int cnt)
{
	int			i;
	t_mapinfo	mapinfo;
	char		*buff;
	ssize_t		rd_size;
	char		**arr;

	i = 0;
	buff = NULL;
	arr = NULL;
	buff = ft_do_charmalloc(buff, cnt);
	rd_size = read(fd, buff, cnt);
	if (rd_size > 0)
	{
		buff[rd_size] = '\0';
		if (!ft_read_first_line(buff, &mapinfo))
			return (0);
		if (!ft_count_y_len(buff, &mapinfo))
			return (0);
		arr = ft_do_malloc(arr, mapinfo);
		ft_set_map(buff, arr, mapinfo);
		free(buff);
		ft_free(arr, mapinfo);
	}
	return (1);
}

int	main(int ac, char **av)
{
	int		fd;
	int		i;
	int		cnt;

	cnt = 0;
	if (ac < 2)
	{
		to_do_std();
		return (0);
	}
	i = 1;
	while (i < ac)
	{
		if (!ft_cnt_file(av, &cnt, i))
		{
			i++;
			continue ;
		}
		close(fd);
		fd = open(av[i], O_RDONLY);
		ft_file_read(fd, cnt);
		close(fd);
		i++;
	}
	return (0);
}
