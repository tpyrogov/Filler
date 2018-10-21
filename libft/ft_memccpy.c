/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpyrogov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 12:08:03 by tpyrogov          #+#    #+#             */
/*   Updated: 2017/11/03 12:08:04 by tpyrogov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	const unsigned char	*s;
	unsigned char		*d;
	unsigned char		ch;
	size_t				i;

	i = 0;
	ch = c;
	if (n)
	{
		s = src;
		d = dest;
		while (n--)
		{
			d[i] = s[i];
			if (s[i] == ch)
			{
				return (&(d[i]) + 1);
			}
			i++;
			d[i] = '\0';
		}
	}
	return (NULL);
}
