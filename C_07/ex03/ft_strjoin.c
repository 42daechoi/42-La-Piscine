/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 15:59:09 by daechoi           #+#    #+#             */
/*   Updated: 2021/09/22 17:10:59 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	j = 0;
	i = ft_strlen(dest);
	while (src[j])
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

int	ft_total_length(char **strs, int size, char *sep)
{
	int	i;
	int	total_len;

	if (size < 0)
		return (0);
	i = 0;
	total_len = 0;
	while (i < size)
		total_len += ft_strlen(strs[i++]);
	total_len += ft_strlen(sep) * (size - 1);
	return (total_len);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	char	*res;
	int		total_len;

	if (size == 0)
	{
		res = (char *)malloc(sizeof(char));
		if (!res)
		{
			res = 0;
			return (0);
		}
	}
	total_len = ft_total_length(strs, size, sep);
	res = (char *)malloc(total_len * sizeof(char) + 1);
	if (!res)
		return (0);
	i = 0;
	while (i < size - 1)
	{
		ft_strcat(res, strs[i]);
		ft_strcat(res, sep);
		i++;
	}
	ft_strcat(res, strs[i]);
	res[total_len] = '\0';
	return (res);
}
