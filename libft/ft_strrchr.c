/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpyrogov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 17:08:37 by tpyrogov          #+#    #+#             */
/*   Updated: 2017/11/03 17:08:39 by tpyrogov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char *str;

	str = s;
	while (*str != '\0')
		str++;
	while (str >= s)
	{
		if (*str == c)
			return ((char*)str);
		str--;
	}
	return (NULL);
}
