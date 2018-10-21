/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_writetil.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpyrogov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 14:30:15 by tpyrogov          #+#    #+#             */
/*   Updated: 2018/05/01 14:30:34 by tpyrogov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_writetil(char **dest, char *src, char sym)
{
	int i;
	int pos;

	i = 0;
	pos = 0;
	while (src[pos] != '\0')
	{
		if (src[pos] == sym)
			break ;
		pos++;
	}
	if (!(*dest = ft_strnew(pos)))
		return (0);
	if (pos != 0)
	{
		while (i < pos)
		{
			*((*dest) + i) = src[i];
			i++;
		}
		*((*dest) + i) = '\0';
	}
	return (pos);
}
