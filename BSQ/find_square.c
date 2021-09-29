/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 18:39:29 by daechoi           #+#    #+#             */
/*   Updated: 2021/09/29 16:50:12 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "header.h"

int	ft_min(int a, int b, int c)
{
	int	min;

	min = a;
	if (min > b)
		min = b;
	if (min > c)
		min = c;
	return (min);
}

void	ft_set_square_len(int **num_arr, t_mapinfo mi)
{
	int	i;
	int	j;
	int	a;
	int	b;
	int	c;

	i = 1;
	while (i < mi.x_len)
	{
		j = 1;
		while (j < mi.y_len)
		{
			if (num_arr[i][j] != 0)
			{
				a = num_arr[i][j - 1];
				b = num_arr[i - 1][j];
				c = num_arr[i - 1][j - 1];
				num_arr[i][j] = ft_min(a, b, c) + 1;
			}
			j++;
		}
		i++;
	}
}

void	ft_change_arr_to_num(char **arr, int **num_arr, t_mapinfo mi)
{
	int	i;
	int	j;

	i = 0;
	while (i < mi.x_len)
	{
		j = 0;
		while (j < mi.y_len)
		{
			if (arr[i][j] == mi.empty)
				num_arr[i][j] = 1;
			if (arr[i][j] == mi.obstacle)
				num_arr[i][j] = 0;
			j++;
		}
		i++;
	}
}

void	ft_put_arr(char *buff, char **arr, t_mapinfo mi)
{
	int	i;
	int	j;
	int	k;

	k = mi.first_len;
	i = 0;
	while (i < mi.x_len)
	{
		j = 0;
		while (j < mi.y_len)
		{
			if (buff[k] == '\n')
				k++;
			arr[i][j] = buff[k];
			j++;
			k++;
		}
		i++;
	}
}

void	ft_set_map(char *buff, char **arr, t_mapinfo mi)
{
	int			**num_arr;
	t_maxinfo	maxinfo;

	num_arr = NULL;
	ft_put_arr(buff, arr, mi);
	if (!ft_check_arr(arr, mi))
	{
		ft_err_msg();
		return ;
	}
	num_arr = ft_do_intmalloc(num_arr, mi);
	ft_change_arr_to_num(arr, num_arr, mi);
	ft_set_square_len(num_arr, mi);
	ft_find_biggest(num_arr, mi, &maxinfo);
	ft_filled_map(arr, mi, maxinfo);
	ft_intfree(num_arr, mi);
}
