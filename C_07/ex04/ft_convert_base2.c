/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 15:53:27 by daechoi           #+#    #+#             */
/*   Updated: 2021/09/27 15:56:22 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


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
	j = 0;
	while (base[j])
	{
		while (base[j] && str[i] != base[j])
			j++;
		if (base[j] == str[i])
			cnt++;
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
