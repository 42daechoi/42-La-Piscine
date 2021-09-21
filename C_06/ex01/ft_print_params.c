/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 18:00:29 by daechoi           #+#    #+#             */
/*   Updated: 2021/09/21 18:05:37 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<unistd.h>

int	main(int argv, char *argc[])
{
	int	i;
	int	j;

	i = 1;
	while (i < argv)
	{
		j = 0;
		while (argc[i][j])
			j++;
		write(1, argc[i], j);
		write(1, "\n", 1);
		i++;
	}
	return (0);
}
