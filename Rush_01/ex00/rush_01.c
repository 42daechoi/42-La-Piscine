/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush_01.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 18:49:14 by daechoi           #+#    #+#             */
/*   Updated: 2021/09/18 21:20:13 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include<stdlib.h>
#include"header.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print(int n)
{
	int	i;
	int	j;

	i = 0;
	while (++i <= n)
	{
		j = 0;
		while (++j <= n)
		{
			ft_putchar(g_arr[i][j] + '0');
			if (j != n)
				ft_putchar(' ');
		}
		ft_putchar('\n');
	}
	return ;
}

int	ft_is_exist(int x, int y, int n)
{
	int	target;
	int	i;

	target = g_arr[x][y];
	i = 0;
	while (++i <= n)
	{
		if (i != y && g_arr[x][i] == target)
			return (1);
	}
	i = 0;
	while (++i <= n)
	{
		if (i != x && g_arr[i][y] == target)
			return (1);
	}
	return (0);
}

void	ft_backtracking(int x, int y, int n)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (x == n + 1 && y == 1)
	{
		while (++i <= n)
		{
			while (++j <= n)
			{
				if (ft_is_correct(i, j, n) != 1)
					return ;
			}
		}
		ft_print(n);
		return ;
	}
	if (x >= 1 && x <= n && y >= 1 && y <= n)
	{
		while (++i <= n)
		{
			g_arr[x][y] = i;
			if (ft_is_exist(x, y, n) == 0)
			{
				if (y != n)
					ft_backtracking(x, y + 1, n);
				else
					ft_backtracking(x + 1, 1, n);
			}
			g_arr[x][y] = 0;
		}
	}
	return ;
}
