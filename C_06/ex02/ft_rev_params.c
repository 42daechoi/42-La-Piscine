/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 18:06:11 by daechoi           #+#    #+#             */
/*   Updated: 2021/09/21 18:10:52 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

int	main(int argv, char *argc[])
{
	int	i;
	int	j;

	i = argv - 1;
	while (i > 0)
	{
		j = 0;
		while (argc[i][j])
			j++;
		write(1, argc[i], j);
		write(1, "\n", 1);
		i--;
	}
	return (0);
}
