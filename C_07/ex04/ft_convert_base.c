/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 17:11:33 by daechoi           #+#    #+#             */
/*   Updated: 2021/09/27 15:53:17 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<unistd.h>

void	ft_putnbr_base(int nbr, char *base)
{
	if (ft_check_base(base) == 0)
	{
		ft_print_nbr_recursive(base, nbr, ft_base_len(base));
	}
}
char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{

