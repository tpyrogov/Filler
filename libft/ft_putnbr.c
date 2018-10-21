/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpyrogov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 16:13:05 by tpyrogov          #+#    #+#             */
/*   Updated: 2017/11/05 16:13:06 by tpyrogov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		ft_putnbr(-21);
		ft_putnbr(47483648);
	}
	else
	{
		if (nb < 0)
		{
			ft_putchar('-');
			nb *= -1;
		}
		if (nb < 10)
		{
			ft_putchar('0' + nb);
		}
		else
		{
			ft_putnbr(nb / 10);
			ft_putchar(nb % 10 + '0');
		}
	}
}
