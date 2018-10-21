/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_nbr_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpyrogov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/25 18:07:29 by tpyrogov          #+#    #+#             */
/*   Updated: 2018/08/25 18:07:30 by tpyrogov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*put_nbr_base(intmax_t num, int base, t_flags *flags)
{
	int		size;
	int		i;
	char	*res;

	i = 0;
	size = count(num, base);
	res = ft_strnew(size);
	if (num < 0)
	{
		flags->neg = 1;
		num *= -1;
	}
	while (size--)
	{
		res[i] = flags->mask[num / power(base, size)];
		num %= power(base, size);
		i++;
	}
	flags->cur = i;
	return (res);
}

char	*put_unsigned_nbr(uintmax_t num, int base, t_flags *flags)
{
	int		size;
	int		i;
	char	*res;

	i = 0;
	size = u_count(num, base);
	flags->cur = size;
	res = ft_strnew(size);
	while (size--)
	{
		res[i++] = flags->mask[num / power(base, size)];
		num %= power(base, size);
	}
	return (res);
}
