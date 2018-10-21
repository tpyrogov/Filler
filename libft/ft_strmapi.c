/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpyrogov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 19:15:03 by tpyrogov          #+#    #+#             */
/*   Updated: 2017/11/07 19:15:04 by tpyrogov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*res;

	i = 0;
	if (s && f)
	{
		res = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
		if (res)
		{
			while (s[i] != '\0')
			{
				res[i] = f(i, s[i]);
				i++;
			}
			res[i] = '\0';
			return (res);
		}
	}
	return (NULL);
}
