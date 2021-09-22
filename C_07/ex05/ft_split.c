/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 17:21:31 by daechoi           #+#    #+#             */
/*   Updated: 2021/09/22 21:08:07 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<stdlib.h>
#include<stdbool.h>

int	ft_count_words(char *str, char *charset)
{
	int		i;
	int		j;
	int 	cnt;
	bool	in_charset;
	bool	is_charset;

	i = 0;
	while (str[i])
	{
		is_charset = false;
		while (charset[j])
		{
			if (charset[j] == str[i])
			{
				is_charset = true;
				break ;
			}
			j++;
		}
		if (is_charset && !in_charset)
			in_charset = true;
		if (!is_charset && in_charset)
		{
			in_charset = false;
			cnt++;
		}
		i++;
	}
	return (cnt);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_count_spells(char *str, char *charset, int words_idx)
{
	int	i;
	int	j;
	int	cnt;
	char *word;

	i = 0;
	while (str[i])
	{
		while (charset[j])
		{

	


char **ft_split(char *str, char *charset)
{
	int		i;
	int		words_cnt;
	char	**res;
	char	*word;

	if (!charset)
		return (0);
	words_cnt = ft_count_words(str, charset);
	res = (char **)malloc(words_cnt * sizeof(char *));
	if (!res)
		return (0);
	i = 0;
	while(i < words_cnt)
	{
		ft_count_spells(str, charset, words_cnt - i);
