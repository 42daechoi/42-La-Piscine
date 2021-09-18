/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 18:49:30 by daechoi           #+#    #+#             */
/*   Updated: 2021/09/18 23:57:07 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef HEADER_H
# define HEADER_H

const int g_length;

int		ft_is_correct(int x, int y, int **arr, int *input);

void	ft_backtracking(int x, int y, int **arr, int *input);

#endif
