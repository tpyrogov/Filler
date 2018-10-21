/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpyrogov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 14:56:20 by tpyrogov          #+#    #+#             */
/*   Updated: 2017/11/03 14:56:21 by tpyrogov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	char *begin;

	begin = dest;
	while (n && *src)
	{
		*dest = *src;
		dest++;
		src++;
		n--;
	}
	while (n)
	{
		*dest = '\0';
		dest++;
		n--;
	}
	return (begin);
}
