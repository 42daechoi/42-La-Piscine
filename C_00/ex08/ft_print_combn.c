/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 22:51:12 by daechoi           #+#    #+#             */
/*   Updated: 2021/09/12 14:54:33 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_num(int *num, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		ft_putchar(num[i] + 48);
		i++;
	}
}

void	ft_set_num(int *num, int digit, int n)
{
	int	i;

	while (1)
	{
		while (num[digit] == 10 - n + digit)
			digit--;
		if (digit < 0)
			return ;
		num[digit]++;
		i = digit;
		while (i < n)
		{
			num[digit + 1] = num[digit] + 1;
			i++;
		}
		digit = n - 1;
		ft_putchar(',');
		ft_putchar(' ');
		ft_print_num(num, n);
	}
}

void	ft_print_combn(int n)
{
	int	num[9];
	int	i;

	i = 0;
	while (i < n)
	{
		num[i] = i;
		i++;
	}
	ft_print_num(num, n);
	ft_set_num(num, n - 1, n);
}
