/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dma.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 23:37:20 by daechoi           #+#    #+#             */
/*   Updated: 2021/09/29 13:35:52 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	**ft_do_malloc(char **arr, t_mapinfo mapinfo)
{
	int	i;

	i = 0;
	arr = (char **)malloc(mapinfo.x_len * sizeof(char *));
	if (!arr)
		exit(1);
	while (i < mapinfo.x_len)
	{
		arr[i] = (char *)malloc(mapinfo.y_len * sizeof(char));
		if (!arr[i])
			exit(1);
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
		exit(1);
	while (i < mapinfo.x_len)
	{
		arr[i] = (int *)malloc(mapinfo.y_len * sizeof(int));
		if (!arr[i])
			exit(1);
		i++;
	}
	return (arr);
}

char	*ft_do_charmalloc(char *arr, int cnt)
{
	int	i;

	i = 0;
	arr = (char *)malloc((cnt + 1) * sizeof(char));
	if (!arr)
		exit(1);
	arr[cnt] = '\0';
	return (arr);
}

void	ft_free(char **arr, t_mapinfo mi)
{
	int	i;

	i = 0;
	while (i < mi.x_len)
		free(arr[i++]);
	free(arr);
}

void	ft_intfree(int **arr, t_mapinfo mi)
{
	int	i;

	i = 0;
	while (i < mi.x_len)
		free(arr[i++]);
	free(arr);
}
