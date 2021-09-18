/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 18:48:57 by daechoi           #+#    #+#             */
/*   Updated: 2021/09/18 19:34:31 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>
#include<unistd.h>
#include "rush_01.h"

int	*g_input;
int	**g_arr;

int	ft_count_length(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (i % 2 == 0 && (str[i] >= 0 && str[i] <= 9))
			return (-1);
		if (i % 2 == 1 && str[i] != 32)
			return (-1);
		i++;
	}
	if ((i + 1) % 8 != 0)
		return (-1);
	return ((i + 1) / 8);
}

void	ft_set_arr_zero(int **arr, int length)
{
	int	i;
	int	j;

	i = 0;
	while (i < length + 2)
	{
		j = 0;
		while (j < length + 2)
		{
			arr[i][j] = 0;
			j++;
		}
		i++;
	}
}

void	ft_set_input(int *g_input, char *argc)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (argc[i])
	{
		if (i % 2 == 0)
		{
			g_input[j] = argc[i] - '0';
			j++;
		}
		i++;
	}
	g_input[j] = '\0';
}

int	main(int argv, char *argc[])
{
	int	length;
	int	i;

	i = 0;
	if (argv != 2)
		write(1, "Input error(filename param)", 27);
	else
	{
		length = ft_count_length(argc[1]);
		if (length == -1)
			write(1, "Input error(param error)", 25);
		else
		{
			g_input = (int *)malloc((length * 4) * sizeof(int));
			g_arr = (int **)malloc((length + 2) * sizeof(int *));
			while (i < length + 2)
				g_arr[i++] = (int *)malloc((length + 2) * sizeof(int));
			ft_set_arr_zero(g_arr, length);
			ft_set_input(g_input, argc[1]);
		}
		ft_backtracking(1, 1, length);
		free(g_arr);
		free(g_input);
	}
	return (0);
}
