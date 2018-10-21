/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpyrogov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 18:03:34 by tpyrogov          #+#    #+#             */
/*   Updated: 2017/11/07 18:03:35 by tpyrogov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strnew(size_t size)
{
	char *s;

	s = (char *)malloc((size + 1) * sizeof(char));
	if (s)
		ft_bzero((void *)s, size + 1);
	return (s);
}
