/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 16:08:58 by daechoi           #+#    #+#             */
/*   Updated: 2021/09/14 11:41:55 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<stdio.h>
void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	temp;

	i = 0;
	while (i < size / 2)
	{
		temp = tab[i];
		tab[i] = tab[size - i - 1];
		tab[size - i - 1] = temp;
		i++;
	}
}

int main() {
	int n[5];
	int i = 0;

	while(i < 5)
	{
		n[i] = i;
		i++;
	}
	ft_rev_int_tab(n, 5);
	i =0;
	while(i < 5) {
		printf("%d ", n[i]);
		i++;
	}
	return 0;
}
