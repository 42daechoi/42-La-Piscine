/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 15:59:09 by daechoi           #+#    #+#             */
/*   Updated: 2021/09/22 17:02:36 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<stdlib.h>
#include<stdio.h>

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
	int total_len;

	if (size < 0)
		return (0);
	i = 0;
	total_len = 0;
	while (i < size)
		total_len += ft_strlen(strs[i++]);
	total_len += ft_strlen(sep) * (size - 1);
	return (total_len);
}

char *ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	char	*res;
	int		total_len;

	if (size == 0)
	{
		if (!(res = (char *)malloc(sizeof(char))))
		{
			res = 0;
			return (0);
		}
	}
	total_len = ft_total_length(strs, size, sep);
	if (!(res = (char *)malloc(total_len * sizeof(char) + 1)))
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

int main(int argv, char **argc)
{
	char *a[4] = {"12", "123", "1234", "12345"};
	char *b = "::";
	char *c;


	c = ft_strjoin(4, a, b);
	printf("%s", c);
}

