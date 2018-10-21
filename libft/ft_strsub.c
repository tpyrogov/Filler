/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpyrogov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 19:45:44 by tpyrogov          #+#    #+#             */
/*   Updated: 2017/11/07 19:45:45 by tpyrogov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	int				j;
	char			*res;

	i = start;
	j = 0;
	res = (char *)malloc((len) + 1 * sizeof(char));
	if (res && s)
	{
		while (i < start + len)
		{
			res[j] = s[i];
			i++;
			j++;
		}
		res[j] = '\0';
	}
	return (res);
}
