/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 18:12:56 by daechoi           #+#    #+#             */
/*   Updated: 2021/09/21 19:31:28 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	ft_swap(char *a, char *b)
{
	char	*temp;

	temp = a;
	a = b;
	b = temp;
}

void	ft_sort_argc(char **argc, int argv)
{
	int	i;
	int	j;
	int	k;

	i = 1;
	while (i < argv)
	{
		j = 1;
		while (j < argv - 1)
		{
			k = 0;
			while (argc[j][k])
			{
				if (argc[j][k] == argc[j + 1][k])
					k++;
				else if (argc[j][k] > argc[j + 1][k])
				{
					ft_swap(argc[j], argc[j + 1]);
					break ;
				}
				else
					break ;
			}
			j++;
		}
		i++;
	}
}

int	main(int argv, char *argc[])
{
	int	i;
	int	j;

	ft_sort_argc(argc, argv);
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
	
