/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 16:49:54 by daechoi           #+#    #+#             */
/*   Updated: 2021/09/15 15:04:01 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<stdio.h>
unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	int	i;

	i = 0;
	while (i < (int)size - 1 && size != 0)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return ((unsigned int)i);
}

int main()
{
	char src[] = "abcdef";
	char dest[] = "as";
	printf("%d", ft_strlcpy(dest, src, 3));
	return 0;
}
