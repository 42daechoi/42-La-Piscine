/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 21:32:08 by daechoi           #+#    #+#             */
/*   Updated: 2021/09/16 21:09:57 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	ft_putnbr(int nb)
{
	char	c;

	if (nb == -2147483648)
	{
		ft_putnbr(nb / 10);
		write(1, &"8", 1);
	}
	else if (nb < 0)
	{
		write(1, &"-", 1);
		ft_putnbr(-nb);
	}
	else
	{	
		if (nb > 9)
		{
			ft_putnbr(nb / 10);
		}
		c = nb % 10 + 48;
		write(1, &c, 1);
	}
}
