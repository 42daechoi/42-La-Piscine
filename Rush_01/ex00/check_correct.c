/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_correct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 20:31:41 by daechoi           #+#    #+#             */
/*   Updated: 2021/09/18 21:20:43 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

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
