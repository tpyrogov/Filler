/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpyrogov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 20:02:04 by tpyrogov          #+#    #+#             */
/*   Updated: 2017/11/07 20:02:05 by tpyrogov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		size;
	char	*res;

	if (s1 && s2)
	{
		size = ft_strlen(s1) + ft_strlen(s2) + 1;
		res = (char *)malloc(size * sizeof(char));
		if (res)
		{
			ft_strcpy(res, s1);
			ft_strcat(res, s2);
			res[size] = '\0';
			return (res);
		}
	}
	return (NULL);
}
