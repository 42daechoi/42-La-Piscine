/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush_01.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 18:49:30 by daechoi           #+#    #+#             */
/*   Updated: 2021/09/18 18:55:24 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

extern int *g_input;
extern int **g_arr;
void ft_putchar(char c);
void ft_print(int n);
int ft_up_is_correct(int x, int y, int n);
int ft_down_is_correct(int x, int y, int n);
int ft_left_is_correct(int x, int y, int n);
int ft_right_is_correct(int x, int y, int n);
int ft_is_exist(int x, int y , int n);
int ft_is_correct(int x, int y, int n);
void ft_backtracking(int x, int y, int n);
