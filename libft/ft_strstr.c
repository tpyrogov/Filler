/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpyrogov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 17:16:49 by tpyrogov          #+#    #+#             */
/*   Updated: 2017/11/03 17:16:51 by tpyrogov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int		i;
	int		j;

	i = 0;
	if (*little == '\0')
		return ((char *)big);
	while (big[i] != '\0')
	{
		j = 0;
		while (little[j] != '\0' && big[i + j] == little[j])
		{
			j++;
			if (little[j] == '\0')
				return ((char *)big + i);
		}
		i++;
	}
	return (0);
}
