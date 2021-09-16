/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 18:09:54 by daechoi           #+#    #+#             */
/*   Updated: 2021/09/16 15:05:48 by daechoi          ###   ########.fr       */
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
	unsigned char	c;

	ascii_16 = "0123456789abcdef";
	i = 0;
	while (str[i] != '\0')
	{
		c = str[i];
		if (c <= 31 || c >= 127)
		{
			ft_putchar('\\');
			ft_putchar(ascii_16[c / 16]);
			ft_putchar(ascii_16[c % 16]);
		}
		else
			ft_putchar(c);
		i++;
	}
}

int main()
{
	char c[] = "hi\nNni\tbji disnl\r»";
	ft_putstr_non_printable(c);
	return 0;
}
