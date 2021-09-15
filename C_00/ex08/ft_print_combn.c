/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 10:50:29 by daechoi           #+#    #+#             */
/*   Updated: 2021/09/14 23:15:10 by daechoi          ###   ########.fr       */
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
			break ;
		num[digit]++;
		i = digit + 1;
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
	int	i;
	int	num[9];

	i = 0;
	while (i < n)
	{
		num[i] = i;
		i++;
	}

	ft_print_num(num, n);
	ft_set_num(num, n - 1, n);
}

int main() {
	ft_print_combn(9);
	return 0;
}
