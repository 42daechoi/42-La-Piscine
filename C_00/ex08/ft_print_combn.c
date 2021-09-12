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

void	ft_print_num(int num[], int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		if (n == 1)
		{
			ft_putchar(num[0] + 48);
		}
		else if (n > 1 && num[n-1] == num[n-2])
		{
			break;
		}
		else
		{
			ft_putchar(num[i] + 48);
			ft_putchar(',');
			ft_putchar(' ');
			i++;
		}	
	}
}

void	ft_set_num(int num[], int digit, int n)
{
		while (num[digit] < 10)
		{
			ft_print_num(num, n);
			num[digit]++;
			if (num[digit] > 10 - n + digit)
			{
				num[digit - 1]++;
				num[digit] = digit;
				digit--;
			}
		}
		//ft_set_num(num, digit - 1, n);
}

void	ft_print_combn(int n)
{
	int num[10];
	int i;

	i = 0;
	while(i < n)
	{
		num[i] = i;
		i++;
	}
	ft_set_num(num, n - 1, n);
}

int	main(void)
{
	ft_print_combn(2);
	return 0;
}
