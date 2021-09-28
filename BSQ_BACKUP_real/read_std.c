/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_std.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiyoon <kiyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 17:41:01 by kiyoon            #+#    #+#             */
/*   Updated: 2021/09/28 15:30:24 by kiyoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	read_byte(char *buff, int size)
{
	char	temp[BUFF_SIZE];
	int		i;
	int		re;

	i = 0;
	while (temp[i])
		temp[++i] = 0;
	re = read(0, temp, size);
	ft_strcat(buff, temp);
	return (re);
}

void	to_cal_temp(t_mapinfo *mapinfo, char *temp)
{
	int	i;
	int	j;

	i = 0;
	while (temp[i] != '\n')
		i++;
	mapinfo->fill = temp[i - 1];
	mapinfo->obstacle = temp[i - 2];
	mapinfo->empty = temp[i - 3];
	temp[i - 3] = '\0';
	mapinfo->x_len = ft_atoi(temp);
	temp[i - 3] = mapinfo->empty;
	mapinfo->first_len = ++i;
	j = i;
	while (temp[j] != '\n')
		j++;
	mapinfo->y_len = j - i;
}

int	depend(t_mapinfo *mapinfo, char *buff)
{
	int	i;
	int	count_n;
	int	j;

	i = 0;
	while (buff[i] != '\n')
		i++;
	j = ++i;
	count_n = 0;
	while (buff[j])
	{
		if (buff[j] == '\n')
		{
			if (j - i != mapinfo->y_len)
				return (0);
			i = ++j;
			count_n++;
		}
		j++;
	}
	if (count_n == mapinfo->x_len)
		return (1);
	return (0);
}

int	read_std(t_mapinfo *mapinfo, char *buff)
{
	char	temp[BUFF_SIZE];
	int		i;

	i = 0;
	while (read_byte(temp, BUFF_SIZE) > 0)
		;
	while (temp[i])
		i++;
	ft_strcpy(buff, temp);
	i = 0;
	to_cal_temp(mapinfo, temp);
	if (!depend(mapinfo, temp))
		return (0);
	return (1);
}

void	to_do_std(void)
{
	char		buff[BUFF_SIZE];
	char		**arr;
	t_mapinfo	mapinfo;

	arr = NULL;
	if (!read_std(&mapinfo, buff))
	{
		ft_err_msg();
		return ;
	}
	arr = ft_do_malloc(arr, mapinfo);
	ft_set_map(buff, arr, mapinfo);
}
