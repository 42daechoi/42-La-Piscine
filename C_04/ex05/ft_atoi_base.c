/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 23:59:05 by daechoi           #+#    #+#             */
/*   Updated: 2021/09/16 20:53:06 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<unistd.h>
#include<stdio.h>

int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	res;

	i = 0;
	sign = -1;
	res = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	while (str[i] == '+' && str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (str[i] - '0') + res * 10;
		i++;
	}
	return (res * sign);
}

int	ft_base_len(char  *base)
{
	int	i;

	i = 0;
	while (base[i])
		i++;
	return (i);
}

void ft_set_notation_recursive(char *base, int nbr, int base_len)
{
	char	c;

	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr = (-nbr);
	}
	else
	{
		if (nbr >= base_len)
			ft_set_notaion_recursive(base, nbr / base_len, base_len);
		c = base[nbr % base_len];
		write(1, &c, 1);
	}
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

int	ft_atoi_base(char *str, char *base)
{
	
}

int main(int argv, char *argc[])
{
	if (argv != 3)
		printf("input error");
	else
		ft_atoi_base(argc[1], argc[2]);
	return 0;
}
