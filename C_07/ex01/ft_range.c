/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 12:26:42 by daechoi           #+#    #+#             */
/*   Updated: 2021/09/22 13:41:31 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

int	*ft_range(int min, int max)
{
	int				*arr;
	unsigned int	arr_len;
	int				i;

	if (min >= max)
		return (0);
	arr_len = max - min;
	printf("%u\n", arr_len);
	if (!(arr = (int *)malloc(arr_len * sizeof(int))))
		return (0);
	printf("%d\n", 1);
	i = 0;
	while (min < max)
	{
		arr[i++] = min++;
		printf("%d %d\n", arr[i], i);
	}
	return (arr);
}
