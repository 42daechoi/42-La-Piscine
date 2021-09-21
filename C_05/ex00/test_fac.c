/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_fac.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 18:03:34 by daechoi           #+#    #+#             */
/*   Updated: 2021/09/21 20:13:48 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<stdio.h>
int	ft_iterative_factorial(int nb)
{
	int	fac;
	int	i;

	if (nb < 1)
		return (0);
	i = 1;
	fac = 1;
	while (i <= nb)
	{
		fac *= i;
		i++;
	}
	return (fac);
}

int main()
{
	printf("%d", ft_iterative_factorial(0));
}
