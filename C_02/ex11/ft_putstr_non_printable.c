/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 18:09:54 by daechoi           #+#    #+#             */
/*   Updated: 2021/09/13 19:18:28 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<unistd.h>
void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr_non_printable(char *str)
{
	 int	i;
	char	*ascii_16;

	ascii_16 = "0123456789abcdef";
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 0 && str[i] <= 31 || str[i] == 127)
		{
			ft_putchar('\\');
			ft_putchar(ascii_16[str[i] / 16]);
			ft_putchar(ascii_16[str[i] % 16]);
		}
		else
			ft_putchar(str[i]);
		i++;
	}
}
