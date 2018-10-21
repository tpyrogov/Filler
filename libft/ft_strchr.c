/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpyrogov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 16:47:35 by tpyrogov          #+#    #+#             */
/*   Updated: 2017/11/03 16:47:37 by tpyrogov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strchr(const char *s, int c)
{
	if (c == '\0')
	{
		while (*s != '\0')
			s++;
		return ((char *)s);
	}
	return (ft_memchr(s, (unsigned char)c, ft_strlen(s)));
}
