/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_mas.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpyrogov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 17:38:56 by tpyrogov          #+#    #+#             */
/*   Updated: 2017/12/01 17:38:58 by tpyrogov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_del_mas(void **mass)
{
	while (mass)
	{
		free(*mass);
		*mass = NULL;
		mass++;
	}
}
