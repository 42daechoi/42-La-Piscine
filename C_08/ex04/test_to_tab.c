/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 21:25:55 by daechoi           #+#    #+#             */
/*   Updated: 2021/09/27 22:14:34 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*str;
	int		i;

	str = (char *)malloc((ft_strlen(src) + 1) * sizeof(char));
	if (!str)
		return (0);
	i = 0;
	while (src[i])
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

struct s_stock_str	*ft_str_to_tab(int ac, char **av)
{
	t_stock_str	*ss;
	int			i;

	i = 0;
	ss = (struct s_stock_str *)malloc((ac + 1) * sizeof(struct s_stock_str));
	if (!ss)
		return (0);
	while (i < ac)
	{
		ss[i].size = ft_strlen(av[i]);
		ss[i].str = av[i];
		ss[i].copy = ft_strdup(av[i]);
		i++;
	}
	ss[ac].str = 0;
	return (ss);
}

int main(int ac, char **av)
{
	t_stock_str	*ss;
	int	i = 0;

	ss = ft_str_to_tab(ac, av);

	while (i < ac)
	{
		printf("%d ", ss[i].size);
		printf("%s ", ss[i].str);
		printf("%s\n", ss[i].copy);
		i++;
	}
	return (0);
}
