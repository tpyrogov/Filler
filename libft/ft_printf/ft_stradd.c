/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stradd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpyrogov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/25 17:55:35 by tpyrogov          #+#    #+#             */
/*   Updated: 2018/08/25 17:55:36 by tpyrogov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		bit_count(unsigned int c)
{
	int i;

	i = 0;
	while ((c = c >> 1))
		i++;
	return (i + 1);
}

char	*ft_stradd(char *s1, char *s2, int size1, int size2)
{
	char	*s;
	int		i;

	i = 0;
	s = ft_strnew(size1 + size2);
	while (i < size1)
	{
		s[i] = *s1;
		s1++;
		i++;
	}
	while (i < size1 + size2)
	{
		s[i] = *s2;
		s2++;
		i++;
	}
	return (s);
}

void	ft_put_str(char *s, int size)
{
	int		i;
	char	c;

	i = 0;
	while (i < size && s != NULL)
	{
		c = s[i];
		write(1, &c, 1);
		i++;
	}
}
