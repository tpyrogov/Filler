/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_format_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpyrogov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/25 17:43:46 by tpyrogov          #+#    #+#             */
/*   Updated: 2018/08/25 17:43:48 by tpyrogov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	uns_form(char **str, t_flags *flags)
{
	if (is_zero(*str) && (flags->width == 0 || flags->precision == 0))
	{
		flags->cur = 0;
		free(*str);
		*str = ft_strnew(0);
	}
	if (flags->precision > -1)
		zero(str, flags->precision, flags);
	if (flags->cur < flags->width)
	{
		if (flags->zero == 1 && flags->minus == 0 && flags->precision == -1)
			zero(str, flags->width, flags);
		else
			space(str, flags);
	}
}

void	hex_form(char **str, t_flags *flags)
{
	if (is_zero(*str) && (flags->width == 0 || flags->precision == 0))
	{
		flags->cur = 0;
		free(*str);
		*str = ft_strnew(0);
	}
	if (flags->precision > -1)
		zero(str, flags->precision, flags);
	if (flags->zero == 1 && flags->minus == 0 && flags->precision == -1)
	{
		if (flags->hash == 1 && ft_atoi(*str) != 0 && flags->spec != p)
			zero(str, flags->width - 2, flags);
		else
			zero(str, flags->width, flags);
	}
	if (flags->hash == 1)
		hash_hex(str, 1, flags);
	if (flags->cur < flags->width)
		space(str, flags);
	if (flags->spec == xcaps)
		to_upper(*str);
}

void	int_form(char **str, t_flags *flags)
{
	if (is_zero(*str) && (flags->width == 0 || flags->precision == 0))
	{
		flags->cur = 0;
		free(*str);
		*str = ft_strnew(0);
	}
	if (flags->precision > 0)
		zero(str, flags->precision, flags);
	if (flags->zero == 1 && flags->minus == 0 && flags->precision == -1)
	{
		if (flags->space == 1 || flags->plus == 1)
			zero(str, flags->width - 1, flags);
		else
			zero(str, flags->width, flags);
	}
	if (flags->plus == 1 || flags->neg == 1)
		plus(str, flags);
	else if (flags->space == 1)
		space_before(str, flags);
	if (flags->minus == 1)
		space(str, flags);
	if (flags->cur < flags->width)
		space(str, flags);
}

void	addr_form(char **str, t_flags *flags)
{
	int size;

	if (is_zero(*str) && flags->precision == 0)
	{
		flags->cur = 0;
		free(*str);
		*str = ft_strnew(0);
	}
	else if (flags->precision > 0)
		zero(str, flags->precision, flags);
	if ((flags->zero == 1 && flags->minus == 0 && flags->precision == -1))
	{
		size = flags->width - 2;
		zero(str, size, flags);
	}
	hash_hex(str, 1, flags);
	if (flags->cur < flags->width)
	{
		if (flags->zero == 1 && flags->minus == 0)
			zero(str, flags->width, flags);
		else
			space(str, flags);
	}
}

void	apply_format(char **str, t_flags *flags)
{
	if (flags->spec == pc)
		perc_form(str, flags);
	else if (flags->spec == c)
		char_form(str, flags);
	else if (flags->spec == d)
		dec_form(str, flags);
	else if (flags->spec == o)
		oct_form(str, flags);
	else if (flags->spec == u)
		uns_form(str, flags);
	else if (flags->spec == x || flags->spec == xcaps)
		hex_form(str, flags);
	else if (flags->spec == p)
		addr_form(str, flags);
	else if (flags->spec == i)
		int_form(str, flags);
}
