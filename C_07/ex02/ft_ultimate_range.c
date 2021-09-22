/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 14:29:01 by daechoi           #+#    #+#             */
/*   Updated: 2021/09/22 17:09:35 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	unsigned int	arr_len;
	int				*arr;
	int				i;

	if (min >= max)
	{
		*range = 0;
		return (0);
	}
	arr_len = max - min;
	arr = (int *)malloc(arr_len * sizeof(int));
	if (!arr)
		return (-1);
	i = 0;
	while (min < max)
		arr[i++] = min++;
	*range = arr;
	return (arr_len);
}
