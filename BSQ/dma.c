/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dma.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 23:37:20 by daechoi           #+#    #+#             */
/*   Updated: 2021/09/26 01:35:40 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	**ft_do_malloc(char **arr, t_mapinfo mapinfo)
{
	int	i;

	i = 0;
	arr = (char **)malloc(mapinfo.x_len * sizeof(char *));
	if (!arr)
	{
		write(1, "memory error", 12);
		exit(1);
	}
	while (i < mapinfo.x_len)
	{
		arr[i] = (char *)malloc(mapinfo.y_len * sizeof(char));
		if (!arr[i])
		{
			write(1, "memory error", 12);
			exit(1);
		}
		i++;
	}
	return (arr);
}

int	**ft_do_intmalloc(int **arr, t_mapinfo mapinfo)
{
	int	i;

	i = 0;
	arr = (int **)malloc(mapinfo.x_len * sizeof(int *));
	if (!arr)
	{
		write(1, "memory error", 12);
		exit(1);
	}
	while (i < mapinfo.x_len)
	{
		arr[i] = (int *)malloc(mapinfo.y_len * sizeof(int));
		if (!arr[i])
		{
			write(1, "memory error", 12);
			exit(1);
		}
		i++;
	}
	return (arr);
}

char	**ft_free(char **arr, t_mapinfo mi)
{
	int	i;

	i = 0;
	free(arr);
	while (i < mi.x_len)
		free(arr[i++]);
	return (arr);
}

int	**ft_intfree(int **arr, t_mapinfo mi)
{
	int	i;
	
	i = 0;
	free(arr);
	while (i < mi.x_len)
		free(arr[i++]);
	return (arr);
}
