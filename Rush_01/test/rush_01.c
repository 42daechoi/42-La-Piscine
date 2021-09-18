/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush_01.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 18:49:14 by daechoi           #+#    #+#             */
/*   Updated: 2021/09/19 00:00:02 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include<stdlib.h>
#include"header.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print(int **arr)
{
	int	i;
	int	j;

	i = 0;
	while (++i <= g_length)
	{
		j = 0;
		while (++j <= g_length)
		{
			ft_putchar(arr[i][j] + '0');
			if (j != g_length)
				ft_putchar(' ');
		}
		ft_putchar('\n');
	}
	return ;
}

int	ft_is_exist(int x, int y, int **arr)
{
	int	target;
	int	i;

	target = arr[x][y];
	i = 0;
	while (++i <= g_length)
	{
		if (i != y && arr[x][i] == target)
			return (1);
	}
	i = 0;
	while (++i <= g_length)
	{
		if (i != x && arr[i][y] == target)
			return (1);
	}
	return (0);
}

void	ft_backtracking(int x, int y, int **arr, int *input)
{
	int	i;
	int	j;

	i = 0;
	if (x == g_length + 1 && y == 1)
	{
		while (++i <= g_length)
		{
			j = 0;
			while (++j <= g_length)
			{
				if (ft_is_correct(i, j, arr, input) != 1)
					return ;
			}
		}
		ft_print(arr);
		return ;
	}
	if (x >= 1 && x <= g_length && y >= 1 && y <= g_length)
	{
		while (++i <= g_length)
		{
			arr[x][y] = i;
			if (ft_is_exist(x, y, arr) == 0)
			{
				if (y != g_length)
					ft_backtracking(x, y + 1, arr, input);
				else
					ft_backtracking(x + 1, 1, arr, input);
			}
			arr[x][y] = 0;
		}
	}
	return ;
}
