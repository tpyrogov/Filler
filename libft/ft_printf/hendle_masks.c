/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hendle_masks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpyrogov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/25 17:57:54 by tpyrogov          #+#    #+#             */
/*   Updated: 2018/08/25 17:57:56 by tpyrogov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	mask1(char **s, unsigned int c, t_flags *flags)
{
	*s = ft_strnew(1);
	(*s)[0] = c;
	flags->cur = 1;
}

void	mask2(char **s, unsigned int c, t_flags *flags)
{
	unsigned char	o1;
	unsigned char	o2;
	unsigned int	mask;

	mask = 49280;
	*s = ft_strnew(2);
	o2 = (c << 26) >> 26;
	o1 = ((c >> 6) << 27) >> 27;
	(*s)[0] = (mask >> 8) | o1;
	(*s)[1] = ((mask << 24) >> 24) | o2;
	flags->cur = 2;
}

void	mask3(char **s, unsigned int c, t_flags *flags)
{
	unsigned int	mask;
	unsigned char	o1;
	unsigned char	o2;
	unsigned char	o3;

	mask = 14712960;
	*s = ft_strnew(3);
	o3 = (c << 26) >> 26;
	o2 = ((c >> 6) << 26) >> 26;
	o1 = ((c >> 12) << 28) >> 28;
	(*s)[0] = (mask >> 16) | o1;
	(*s)[1] = ((mask << 16) >> 24) | o2;
	(*s)[2] = ((mask << 24) >> 24) | o3;
	flags->cur = 3;
}

void	mask4(char **s, unsigned int c, t_flags *flags, unsigned int mask)
{
	unsigned char	o4;
	unsigned char	o3;
	unsigned char	o2;
	unsigned char	o1;

	*s = ft_strnew(4);
	o4 = (c << 26) >> 26;
	o3 = ((c >> 6) << 26) >> 26;
	o2 = ((c >> 12) << 26) >> 26;
	o1 = ((c >> 18) << 29) >> 29;
	(*s)[0] = (mask >> 24) | o1;
	(*s)[1] = ((mask << 8) >> 24) | o2;
	(*s)[2] = ((mask << 16) >> 24) | o3;
	(*s)[3] = ((mask << 24) >> 24) | o4;
	flags->cur = 4;
}
