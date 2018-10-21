/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpyrogov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/25 18:10:49 by tpyrogov          #+#    #+#             */
/*   Updated: 2018/08/25 18:10:57 by tpyrogov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*dec_type(va_list ap, t_flags *flags, int caps)
{
	if (flags->ref == H && caps == 0)
		return (put_nbr_base((short int)va_arg(ap, int), 10, flags));
	else if (flags->ref == HH && caps == 0)
		return (put_nbr_base((signed char)va_arg(ap, int), 10, flags));
	else if (flags->ref == L)
		return (put_nbr_base(va_arg(ap, long int), 10, flags));
	else if (flags->ref == LL)
		return (put_nbr_base(va_arg(ap, long long int), 10, flags));
	else if (flags->ref == Z && caps == 1)
		return (put_nbr_base(va_arg(ap, size_t), 10, flags));
	else if (flags->ref == J && caps == 1)
		return (put_nbr_base(va_arg(ap, intmax_t), 10, flags));
	else if (flags->ref == Z && caps == 0)
		return (put_nbr_base(va_arg(ap, size_t), 10, flags));
	else if (flags->ref == J && caps == 0)
		return (put_nbr_base(va_arg(ap, intmax_t), 10, flags));
	else if (caps == 1)
		return (put_nbr_base(va_arg(ap, long), 10, flags));
	else
		return (put_nbr_base(va_arg(ap, int), 10, flags));
}

char	*octal_type(va_list ap, t_flags *flags, int caps)
{
	if (flags->ref == H && caps == 0)
		return (put_nbr_base((unsigned short int)va_arg(ap, int), 8, flags));
	else if (flags->ref == HH && caps == 0)
		return (put_nbr_base((unsigned char)va_arg(ap, int), 8, flags));
	else if (flags->ref == L)
		return (put_unsigned_nbr(va_arg(ap, unsigned long int), 8, flags));
	else if (flags->ref == LL)
		return (put_unsigned_nbr(va_arg(ap, unsigned long long int), 8, flags));
	else if (flags->ref == Z)
		return (put_unsigned_nbr(va_arg(ap, size_t), 8, flags));
	else if (flags->ref == J)
		return (put_unsigned_nbr(va_arg(ap, uintmax_t), 8, flags));
	else if (flags->ref == NONE && caps == 0)
		return (put_unsigned_nbr(va_arg(ap, unsigned int), 8, flags));
	else
		return (put_unsigned_nbr(va_arg(ap, unsigned long), 8, flags));
}

char	*unsigned_type(va_list ap, t_flags *flags, int caps)
{
	if (flags->ref == H && caps == 0)
		return (put_unsigned_nbr((unsigned short)va_arg(ap, int), 10, flags));
	else if (flags->ref == HH && caps == 0)
		return (put_unsigned_nbr((unsigned char)va_arg(ap, int), 10, flags));
	else if (flags->ref == L)
		return (put_unsigned_nbr(va_arg(ap, unsigned long int), 10, flags));
	else if (flags->ref == LL)
		return (put_unsigned_nbr(
				va_arg(ap, unsigned long long int), 10, flags));
	else if (flags->ref == Z)
		return (put_unsigned_nbr(va_arg(ap, size_t), 10, flags));
	else if (flags->ref == J)
		return (put_unsigned_nbr(va_arg(ap, uintmax_t), 10, flags));
	else if (flags->ref == NONE && caps == 0)
		return (put_unsigned_nbr(va_arg(ap, unsigned int), 10, flags));
	else
		return (put_unsigned_nbr(va_arg(ap, unsigned long), 10, flags));
}

char	*hex_type(va_list ap, t_flags *flags, int p)
{
	if (flags->ref == H)
		return (put_nbr_base((unsigned short)va_arg(ap, int), 16, flags));
	else if (flags->ref == HH)
		return (put_nbr_base((unsigned char)va_arg(ap, int), 16, flags));
	else if (flags->ref == L)
		return (put_unsigned_nbr(va_arg(ap, unsigned long int), 16, flags));
	else if (flags->ref == LL)
		return (put_unsigned_nbr(
				va_arg(ap, unsigned long long int), 16, flags));
	else if (flags->ref == Z)
		return (put_unsigned_nbr(va_arg(ap, size_t), 16, flags));
	else if (flags->ref == J)
		return (put_unsigned_nbr(va_arg(ap, uintmax_t), 16, flags));
	else if (flags->ref == NONE && p == 0)
		return (put_nbr_base(va_arg(ap, unsigned int), 16, flags));
	else
		return (put_nbr_base((long)va_arg(ap, void *), 16, flags));
}

char	*per(t_flags *flags)
{
	char *s;

	s = ft_strnew(1);
	s[0] = '%';
	flags->cur = 1;
	return (s);
}
