/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_correct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 20:31:41 by daechoi           #+#    #+#             */
/*   Updated: 2021/09/19 00:00:33 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_up_is_correct(int x, int y, int **arr, int *input)
{
	int	temp;
	int	cnt;
	int	i;

	temp = -1;
	i = 0;
	cnt = 0;
	while (++i <= g_length)
	{
		if (arr[i][y] > temp)
		{
			temp = arr[i][y];
			cnt++;
		}
	}
	if (cnt != input[y - 1])
		return (0);
	return (1);
}

int	ft_down_is_correct(int x, int y, int **arr, int *input)
{
	int	temp;
	int	cnt;
	int	i;

	temp = -1;
	i = 0;
	cnt = 0;
	while (++i <= g_length)
	{
		if (arr[g_length - i + 1][y] > temp)
		{
			temp = arr[g_length - i + 1][y];
			cnt++;
		}
	}
	if (cnt != input[g_length + y - 1])
		return (0);
	return (1);
}

int	ft_left_is_correct(int x, int y, int **arr, int *input)
{
	int	temp;
	int	cnt;
	int	i;

	temp = -1;
	i = 0;
	cnt = 0;
	while (++i <= g_length)
	{
		if (arr[x][i] > temp)
		{
			temp = arr[x][i];
			cnt++;
		}
	}
	if (cnt != input[g_length * 2 + x - 1])
		return (0);
	return (1);
}

int	ft_right_is_correct(int x, int y, int **arr, int *input)
{
	int	temp;
	int	cnt;
	int	i;

	temp = -1;
	i = 0;
	cnt = 0;
	while (++i <= g_length)
	{
		if (arr[x][g_length - i + 1] > temp)
		{
			temp = arr[x][g_length - i + 1];
			cnt++;
		}
	}
	if (cnt != input[g_length * 3 + x - 1])
		return (0);
	return (1);
}

int	ft_is_correct(int x, int y, int **arr, int *input)
{
	if (ft_up_is_correct(x, y, arr, input) == 0)
		return (0);
	if (ft_down_is_correct(x, y, arr, input) == 0)
		return (0);
	if (ft_left_is_correct(x, y, arr, input) == 0)
		return (0);
	if (ft_right_is_correct(x, y, arr, input) == 0)
		return (0);
	return (1);
}
