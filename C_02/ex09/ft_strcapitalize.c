/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 15:44:04 by daechoi           #+#    #+#             */
/*   Updated: 2021/09/14 17:47:51 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<stdio.h>
char	*ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] + 32;
		i++;
	}
	return (str);
}

char	*ft_first_Upcase(char *str)
{
	if (str[0] >= 'a' && str[0] <= 'z')
		str[0] = str[0] - 32;
	return (str);
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	ft_strlowcase(str);
	ft_first_Upcase(str);
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 32 && str[i] <= 47
			|| str[i] >= 58 && str[i] <= 64
			|| str[i] >= 91 && str[i] <= 96
			|| str[i] >= 123 && str[i] <= 126)
		{
			i++;
			if (str[i] == '\0')
				break ;
			if (str[i] >= 'a' && str[i] <= 'z')
				str[i] = str[i] - 32;
			else
				i--;
		}
		i++;
	}
	return (str);
}

int main() {
	char s[] = "salut, comment tu vas ? 42mots quareate-deux; cinquante+et+un";
	ft_strcapitalize(s);
	printf("%s", s);
	return 0;
}

