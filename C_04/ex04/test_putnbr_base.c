/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_putnbr_base.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 22:01:27 by daechoi           #+#    #+#             */
/*   Updated: 2021/09/16 00:21:02 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>

int	ft_base_len(char *base)
{
	int	i;

	i = 0;
	while (base[i])
		i++;
	return (i);
}

void	ft_print_nbr_recursive(char *base, int nbr, int base_len)
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
			ft_print_nbr_recursive(base, nbr / base_len, base_len);
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

void	ft_putnbr_base(int nbr, char *base)
{
	if (ft_check_base(base) == 0)
	{
		ft_print_nbr_recursive(base, nbr, ft_base_len(base));
	}
}

int main(int argv, char *argc[])
{
	if (argv != 3)
		printf("Input Error");
	else
		ft_putnbr_base(atoi(argc[1]), argc[2]);
	return 0;
}
