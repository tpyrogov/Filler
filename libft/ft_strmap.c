/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpyrogov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 19:06:08 by tpyrogov          #+#    #+#             */
/*   Updated: 2017/11/07 19:06:09 by tpyrogov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*res;
	int		i;

	i = 0;
	if (s && f)
	{
		res = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
		if (res)
		{
			while (s[i] != '\0')
			{
				res[i] = f(s[i]);
				i++;
			}
			res[i] = '\0';
			return (res);
		}
	}
	return (NULL);
}
