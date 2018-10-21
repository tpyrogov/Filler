/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpyrogov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 17:25:23 by tpyrogov          #+#    #+#             */
/*   Updated: 2017/11/02 17:25:24 by tpyrogov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char *d;

	if (n)
	{
		d = s;
		while (n)
		{
			*d = (unsigned char)c;
			d++;
			n--;
		}
	}
	return (s);
}
