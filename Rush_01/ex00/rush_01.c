/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush_01.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 18:49:14 by daechoi           #+#    #+#             */
/*   Updated: 2021/09/18 19:51:56 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include<stdlib.h>
#include"rush_01.h"

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
			ft_putchar(g_arr[i][j] + '0');
		ft_putchar('\n');
	}
	return ;
}

int	ft_up_is_correct(int x, int y, int n)
{
	int	temp;
	int	cnt;
	int	i;

	temp = -1;
	i = 0;
	cnt = 0;
	while (++i <= n)
	{
		if (g_arr[i][y] > temp)
		{
			temp = g_arr[i][y];
			cnt++;
		}
	}
	if (cnt != g_input[y - 1])
		return (0);
	return (1);
}

int	ft_down_is_correct(int x, int y, int n)
{
	int	temp;
	int	cnt;
	int	i;

	temp = -1;
	i = 0;
	cnt = 0;
	while (++i <= n)
	{
		if (g_arr[n - i + 1][y] > temp)
		{
			temp = g_arr[n - i + 1][y];
			cnt++;
		}
	}
	if (cnt != g_input[n + y - 1])
		return (0);
	return (1);
}

int	ft_left_is_correct(int x, int y, int n)
{
	int	temp;
	int	cnt;
	int	i;

	temp = -1;
	i = 0;
	cnt = 0;
	while (++i <= n)
	{
		if (g_arr[x][i] > temp)
		{
			temp = g_arr[x][i];
			cnt++;
		}
	}
	if (cnt != g_input[n * 2 + x - 1])
		return (0);
	return (1);
}

int	ft_right_is_correct(int x, int y, int n)
{
	int	temp;
	int	cnt;
	int	i;

	temp = -1;
	i = 0;
	cnt = 0;
	while (++i <= n)
	{
		if (g_arr[x][n - i + 1] > temp)
		{
			temp = g_arr[x][n - i + 1];
			cnt++;
		}
	}
	if (cnt != g_input[n * 3 + x - 1])
		return (0);
	return (1);
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

int	ft_is_correct(int x, int y, int n)
{
	if (ft_up_is_correct(x, y, n) == 0)
		return (0);
	if (ft_down_is_correct(x, y, n) == 0)
		return (0);
	if (ft_left_is_correct(x, y, n) == 0)
		return (0);
	if (ft_right_is_correct(x, y, n) == 0)
		return (0);
	return (1);
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
