/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_mass_el.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpyrogov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 17:25:10 by tpyrogov          #+#    #+#             */
/*   Updated: 2017/12/01 17:25:11 by tpyrogov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

size_t	ft_count_mass_el(void **mass)
{
	int i;

	i = 0;
	while ((unsigned char)*mass)
	{
		i++;
		mass--;
	}
	mass += i;
	while ((unsigned char)*mass)
	{
		i++;
		mass++;
	}
	return (i);
}
