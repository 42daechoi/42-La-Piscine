/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiyoon <kiyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 01:21:13 by kiyoon            #+#    #+#             */
/*   Updated: 2021/09/26 18:48:11 by kiyoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_atoi(char *str)
{
	long	min;
	long	i;
	long	ans;

	i = 0;
	ans = 0;
	min = 1;
	while (str[i] >= '0' && str[i] <= '9')
		ans = ans * 10 + str[i++] - '0';
	return ((int)(ans * min));
}
