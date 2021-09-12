/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 16:05:03 by daechoi           #+#    #+#             */
/*   Updated: 2021/09/12 20:34:24 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	ft_putstr(char *str)
{
	char	next_c;

	while (*str != '\0')
	{
		next_c = *str;
		write(1, &next_c, 1);
		str++;
	}
}

int main() {
	ft_putstr("Hello world");
	return 0;
}
