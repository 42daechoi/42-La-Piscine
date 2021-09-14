/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 16:02:06 by daechoi           #+#    #+#             */
/*   Updated: 2021/09/14 11:33:42 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<stdio.h>
void	ft_ultimate_div_mod(int *a, int *b)
{
	int	c;

	c = *a / *b;
	*b = *a % *b;
	*a = c;
}

int main() {
	int a =1;
	int b =2;
	ft_ultimate_div_mod(&a,&b);
	printf("%d %d", a,b);
	return 0;
}
