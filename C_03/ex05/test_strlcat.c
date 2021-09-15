/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strlcat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 13:45:08 by daechoi           #+#    #+#             */
/*   Updated: 2021/09/15 14:56:56 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<stdio.h>
unsigned int	ft_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	int				i;
	int				j;
	unsigned int	dest_len;
	unsigned int	src_len;

	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	i = 0;
	j = (int)dest_len;
	while (src[i] && i < (int)(size - dest_len - 1))
	{
		dest[j] = src[i];
		i++;
		j++;
	}
	dest[j] = '\0';
	if (dest_len > size)
		return (size + src_len);
	else
		return (dest_len + (unsigned int)i);
}

int main(){
	char a[] = "abc";
	char b[] = "def";

	printf("%u\n", ft_strlcat(a, b, 7));
	printf("%s", a);
}
