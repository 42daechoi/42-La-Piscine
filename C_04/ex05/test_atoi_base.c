/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_atoi_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 23:59:05 by daechoi           #+#    #+#             */
/*   Updated: 2021/09/22 19:11:20 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<unistd.h>
#include<stdio.h>

int	ft_check_str_len(char *str, char *base)
{
	int	i;
	int	cnt;
	int	j;

	i = 0;
	cnt = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	while (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i])
	{
		j = 0;
		while (base[j] && str[i] != base[j])
			j++;
		if (base[j] == str[i])
			cnt++;
		else
			return (cnt);
		i++;
	}
	return (cnt);
}

int	ft_base_len(char *base)
{
	int	i;

	i = 0;
	while (base[i])
		i++;
	return (i);
}

int	ft_check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (ft_base_len(base) > 1)
	{
		if (base[0] == '\\' && base[1] == '0')
			return (1);
	}
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (1);
		j = i + 1;
		while (base[j])
		{
			if (base[j] == base[i])
				return (1);
			j++;
		}
		i++;
	}
	if (i <= 1)
		return (1);
	return (0);
}

int	ft_start_index(char *str, int *sign)
{
	int	i;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			*sign *= -1;
		i++;
	}
	return (i);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	sign;
	int	correct_str_len;
	int	res;
	int	j;

	if (ft_check_base(base) == 1)
		return (0);
	res = 0;
	sign = 1;
	correct_str_len = ft_check_str_len(str, base);
	i = ft_start_index(str, &sign);
	while (correct_str_len > 0)
	{
		j = 0;
		while (str[i] != base[j])
			j++;
		res = res * ft_base_len(base) + j;
		i++;
		correct_str_len--;
	}
	return (res * sign);
}

int main(int argv, char *argc[])
{
	if (argv != 3)
		printf("input error");
	else
		printf("%d", ft_atoi_base(argc[1], argc[2]));
	return 0;
}
