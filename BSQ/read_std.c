/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_std.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiyoon <kiyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 17:41:01 by kiyoon            #+#    #+#             */
/*   Updated: 2021/09/29 18:18:41 by kiyoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	read_byte(char *buff, int size)
{
	char	*temp;
	int		i;
	int		re;

	temp = malloc_buff_size();
	i = 0;
	while (temp[i])
		temp[++i] = 0;
	re = read(0, temp, size);
	ft_strcat(buff, temp);
	free(temp);
	return (re);
}

int	to_cal_temp(t_mapinfo *mapinfo, char *temp)
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
	if (mapinfo->x_len == 0)
		return (0);
	temp[i - 3] = mapinfo->empty;
	mapinfo->first_len = ++i;
	j = i;
	while (temp[j] != '\n')
		j++;
	mapinfo->y_len = j - i;
	return (1);
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
	if (count_n == mapinfo->x_len && mapinfo->x_len != 0)
		return (1);
	return (0);
}

int	read_std(t_mapinfo *mapinfo, char *buff)
{
	char	*temp;
	int		i;

	temp = malloc_buff_size();
	i = 0;
	while (read_byte(temp, BUFF_SIZE) > 0)
		;
	if (ft_strlen(temp) == 0)
	{
		free(temp);
		return (0);
	}
	ft_strcpy(buff, temp);
	if (!to_cal_temp(mapinfo, temp))
	{
		free(temp);
		return (0);
	}
	if (!depend(mapinfo, temp) || ft_strlen(temp) == 0)
	{
		free(temp);
		return (0);
	}
	free(temp);
	return (1);
}

void	to_do_std(void)
{
	char		*buff;
	char		**arr;
	t_mapinfo	mapinfo;

	buff = malloc_buff_size();
	arr = NULL;
	if (!read_std(&mapinfo, buff))
	{
		ft_err_msg();
		free(buff);
		return ;
	}
	arr = ft_do_malloc(arr, mapinfo);
	ft_set_map(buff, arr, mapinfo);
	free(buff);
}
