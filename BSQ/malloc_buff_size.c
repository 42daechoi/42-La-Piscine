/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_buff_size.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiyoon <kiyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 14:10:00 by kiyoon            #+#    #+#             */
/*   Updated: 2021/09/29 14:53:17 by kiyoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*malloc_buff_size(void)
{
	char	*buff;

	buff = (char *)malloc(sizeof(char) * 300000000);
	return (buff);
}
