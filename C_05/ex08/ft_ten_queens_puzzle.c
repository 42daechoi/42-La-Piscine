/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 23:27:40 by daechoi           #+#    #+#             */
/*   Updated: 2021/09/21 00:41:48 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<stdbool.h>
#include<unistd.h>

void	ft_print_position(int *board)
{
	int		i;
	char	c;

	i = 0;
	while (i < 10)
	{
		c = board[i] + 48;
		write(1, &c, 1);
		i++;
	}
	write(1, "\n", 1);
}		

bool	ft_check_board(int *board, int y)
{
	int	i;

	i = 0;
	while (i < y)
	{
		if (board[i] == board[y])
			return (false);
		if (board[i] == board[y] - (y - i) || board[i] == board[y] + (y - i))
			return (false);
		i++;
	}
	return (true);
}

void ft_backtracking(int *board, int y, int *cnt)
{
	int	x;

	if (y == 10)
	{
		*cnt += 1;
		ft_print_position(board);
	}
	else
	{
		x = 0;
		while (x < 10)
		{
			board[y] = x;
			if (ft_check_board(board, y))
				ft_backtracking(board, y + 1, cnt);
			x++;
		}
		board[y] = 0;
	}
}

int	ft_ten_queens_puzzle(void)
{
	int board[10];
	int	i;
	int cnt;

	i = 0;
	while (i < 10)
		board[i++] = 0;
	ft_backtracking(board, 0, &cnt);
	return (cnt);
}
