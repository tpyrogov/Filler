/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpyrogov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 11:15:47 by tpyrogov          #+#    #+#             */
/*   Updated: 2017/11/03 11:15:49 by tpyrogov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	void *head;

	head = dst;
	if (n)
	{
		while (n)
		{
			*((char *)dst) = *((char *)src);
			dst++;
			src++;
			n--;
		}
	}
	return (head);
}
