/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpyrogov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 14:46:48 by tpyrogov          #+#    #+#             */
/*   Updated: 2017/11/05 14:46:49 by tpyrogov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int		compare;
	size_t	i;

	i = 0;
	compare = 0;
	if (n == 0)
		return (0);
	while (1)
	{
		compare = (unsigned char)s1[i] - (unsigned char)s2[i];
		if ((s1[i] == '\0' && s2[i] == '\0') || (i >= n - 1))
		{
			return (compare);
		}
		if (s1[i] == s2[i])
		{
			i++;
		}
		else
		{
			return (compare);
		}
	}
	return (0);
}
