/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 18:48:57 by daechoi           #+#    #+#             */
/*   Updated: 2021/09/19 13:13:50 by taeslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>
#include<unistd.h>
#include "header.h"

const int	g_length = 4;

int	ft_check_input(char *str)
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
	if (i != 31)
		return (-1);
	return (0);
}

void	ft_set_arr_zero(int **arr)
{
	int	i;
	int	j;

	i = 1;
	while (i < g_length + 2)
	{
		j = 1;
		while (j < g_length + 2)
		{
			arr[i][j] = 0;
			j++;
		}
		i++;
	}
}

void	ft_set_input(int *input, char *argc)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (argc[i])
	{
		if (i % 2 == 0)
		{
			input[j] = argc[i] - '0';
			j++;
		}
		i++;
	}
	input[j] = '\0';
}

void	ft_free_mem(int **arr, int *input)
{
	int	i;

	i = 0;
	free(input);
	while (++i < g_length + 2)
		free(arr[i]);
	free(arr);
}

int	main(int argv, char *argc[])
{
	int	**arr;
	int	*input;
	int	i;

	i = 0;
	if (argv != 2)
		write(1, "Input error(filename param)", 27);
	else
	{
		if (ft_check_input(argc[1]) == -1)
			write(1, "Input error(param error)", 24);
		else
		{
			input = (int *)malloc((g_length * 4) * sizeof(int));
			arr = (int **)malloc((g_length + 2) * sizeof(int *));
			while (++i < g_length + 2)
				arr[i] = (int *)malloc((g_length + 2) * sizeof(int));
			ft_set_arr_zero(arr);
			ft_set_input(input, argc[1]);
			ft_backtracking(1, 1, arr, input);
			ft_free_mem(arr, input);
		}
	}
	return (0);
}
