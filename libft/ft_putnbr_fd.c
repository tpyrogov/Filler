/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpyrogov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 20:37:33 by tpyrogov          #+#    #+#             */
/*   Updated: 2017/11/07 20:37:34 by tpyrogov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_putnbr_fd(int nb, int fd)
{
	if (nb == -2147483648)
	{
		ft_putnbr_fd(-21, fd);
		ft_putnbr_fd(47483648, fd);
	}
	else
	{
		if (nb < 0)
		{
			ft_putchar_fd('-', fd);
			nb *= -1;
		}
		if (nb < 10)
		{
			ft_putchar_fd('0' + nb, fd);
		}
		else
		{
			ft_putnbr_fd(nb / 10, fd);
			ft_putchar_fd(nb % 10 + '0', fd);
		}
	}
}
