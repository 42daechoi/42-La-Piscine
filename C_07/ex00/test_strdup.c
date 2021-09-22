/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strdup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 12:02:38 by daechoi           #+#    #+#             */
/*   Updated: 2021/09/22 12:23:23 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>
#include<stdio.h>

char	*ft_strdup(char *src)
{
	int		i;
	char	*temp;

	i = 0;
	while (src[i])
		i++;
	temp = (char *)malloc(i * sizeof(char));
	i = 0;
	while (src[i])
	{
		temp[i] = src[i];
		i++;
	}
	temp[i] = '\0';
	return (temp);
}

int main()
{
	char *a = "abcde";
	char *b = NULL;

	if ((b = ft_strdup(a)) != NULL)
		printf("%s", b);
	else
		return (1);
	free(b);
	system("leaks a.out");
	return (0);
}
