/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpyrogov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 14:13:18 by tpyrogov          #+#    #+#             */
/*   Updated: 2017/11/05 14:13:19 by tpyrogov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	const unsigned char *c1;
	const unsigned char *c2;

	c1 = (const unsigned char *)s1;
	c2 = (const unsigned char *)s2;
	while (*c1 == *c2 && *c1 != '\0' && *c2 != '\0')
	{
		c1++;
		c2++;
	}
	return (*c1 - *c2);
}
