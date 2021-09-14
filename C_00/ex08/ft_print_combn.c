/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 10:50:29 by daechoi           #+#    #+#             */
/*   Updated: 2021/09/14 15:28:39 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>


void	ft_print_num(int *num, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		write(1, &num[i], 1);
		i++;
	}
}

void	ft_set_num(int *num, int digit, int n)
{
	int	i;
	while(1)
	{
		if (num[digit] == 10 - n + digit)
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
	ft_print_combn(3);
	return 0;
}
