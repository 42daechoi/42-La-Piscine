/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   biggest.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 00:03:00 by daechoi           #+#    #+#             */
/*   Updated: 2021/09/26 01:25:52 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_print_arr(char **arr, t_mapinfo mi)
{
	int	i;
	int	j;
	
	i = 0;
	while (i < mi.x_len)
	{
		j = 0;
		while (j < mi.y_len)
		{
			write(1, &arr[i][j], 1);
			write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

void	ft_find_biggest(int **num_arr, t_mapinfo mi, t_maxinfo *maxinfo)
{
	int	i;
	int	j;
	int	max;
	int max_x;
	int max_y;

	i = 0;
	max = 0;
	while (i < mi.x_len)
	{
		j = 0;
		while (j < mi.y_len)
		{
			if (max < num_arr[i][j])
			{
				max = num_arr[i][j];
				max_x = i;
				max_y = j;
			}
			j++;
		}
		i++;
	}
	maxinfo->max_x = max_x;
	maxinfo->max_y = max_y;
	maxinfo->max_len = max;
}

void	ft_filled_map(char **arr, t_mapinfo mi, t_maxinfo maxinfo)
{
	int	i;
	int	j;
	int	x;
	int	y;

	x = maxinfo.max_x;
	i = 0;
	while (i < maxinfo.max_len)
	{
		j = 0;
		y = maxinfo.max_y;
		while (j < maxinfo.max_len)
		{
			arr[x][y] = mi.fill;
			j++;
			y--;
		}
		i++;
		x--;
	}
	i = 0;
	while (i < mi.x_len)
	{
		j = 0;
		while (j < mi.y_len)
		{
			printf("%c ", arr[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
		
}
