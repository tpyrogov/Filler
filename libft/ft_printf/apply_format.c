/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpyrogov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/25 17:40:56 by tpyrogov          #+#    #+#             */
/*   Updated: 2018/08/25 17:41:03 by tpyrogov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	perc_form(char **str, t_flags *flags)
{
	if (flags->minus == 1)
		space(str, flags);
	if (flags->zero == 1)
		zero(str, flags->width, flags);
	if (flags->cur < flags->width)
		space(str, flags);
	if (flags->precision > -1 && flags->width == 0)
		zero(str, flags->precision, flags);
}

void	change_str(char **res, t_flags *flags)
{
	if (flags->spec == scaps &&
			flags->precision > -1 && flags->precision < flags->cur)
		cut_scaps(res, flags);
	if (flags->precision > -1 &&
			flags->precision < flags->cur && flags->spec != NON)
		cut(res, flags);
	if (flags->width > 0 || flags->zero == 1 || flags->minus == 1)
	{
		if (flags->minus == 1)
			space(res, flags);
		else if (flags->zero == 0)
			space(res, flags);
		else
			zero(res, flags->width, flags);
	}
}

void	char_form(char **str, t_flags *flags)
{
	if (flags->minus == 1)
		space(str, flags);
	if (flags->zero == 1)
		zero(str, flags->width, flags);
	if (flags->cur < flags->width)
		space(str, flags);
	if (flags->precision > -1 && flags->width == 0)
		space(str, flags);
}

void	dec_form(char **str, t_flags *flags)
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
		if (flags->plus == 1 || flags->space == 1 || flags->neg == 1)
			zero(str, flags->width - 1, flags);
		else
			zero(str, flags->width, flags);
	}
	if (flags->plus == 1 || flags->neg == 1)
		plus(str, flags);
	if (flags->space == 1)
		space_before(str, flags);
	if (flags->cur < flags->width)
		space(str, flags);
}

void	oct_form(char **str, t_flags *flags)
{
	if (is_zero(*str) && (flags->width == 0 || flags->precision == 0))
	{
		flags->cur = 0;
		free(*str);
		*str = ft_strnew(0);
	}
	if (flags->hash == 1)
		hash(str, flags);
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
