/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpyrogov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 14:27:21 by tpyrogov          #+#    #+#             */
/*   Updated: 2017/11/03 14:27:22 by tpyrogov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strdup(const char *s)
{
	char	*str;
	int		size;
	int		i;

	i = 0;
	str = NULL;
	if (s)
	{
		size = ft_strlen(s);
		if ((str = (char *)malloc((size + 1) * sizeof(char))))
		{
			while (size--)
			{
				str[i] = s[i];
				i++;
			}
			str[i] = '\0';
		}
		return (str);
	}
	return (NULL);
}
