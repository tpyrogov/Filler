/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpyrogov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 14:45:52 by tpyrogov          #+#    #+#             */
/*   Updated: 2018/08/13 14:45:55 by tpyrogov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*get_spec(va_list ap, char *str, t_flags *flags)
{
	char *s;

	if (*str == 'C' || (*str == 'c' && flags->ref == L))
	{
		put_char_loc(va_arg(ap, wchar_t), &s, flags);
		return (s);
	}
	else if (*str == 'c')
		return (put_char((char)va_arg(ap, int), flags));
	else if (*str == 'p')
		return (hex_type(ap, flags, 1));
	else if (*str == 'O')
		return (octal_type(ap, flags, 1));
	else if (*str == 'U')
		return (unsigned_type(ap, flags, 1));
	else if (*str == '%')
		return (per(flags));
	else if (ft_strlen(str) == 0)
	{
		flags->cur = 0;
		return (NULL);
	}
	else
		return (put_char(*str, flags));
}

char	*find_type(va_list ap, char *str, t_flags *flags)
{
	if (*str == 'd' || *str == 'i')
		return (dec_type(ap, flags, 0));
	else if (*str == 'D')
		return (dec_type(ap, flags, 1));
	else if (*str == 'o')
		return (octal_type(ap, flags, 0));
	else if (*str == 'u')
		return (unsigned_type(ap, flags, 0));
	else if (*str == 'x')
		return (hex_type(ap, flags, 0));
	else if (*str == 'X')
		return (to_upper(hex_type(ap, flags, 0)));
	else if (*str == 's' && flags->ref != L)
		return (str_out(va_arg(ap, char *), flags));
	else if (*str == 'S' || (*str == 's' && flags->ref == L))
		return (put_str_loc(va_arg(ap, wchar_t *), flags));
	else
		return (get_spec(ap, str, flags));
}

void	spec(t_flags *flags, char ch)
{
	if (ch == 'd' || ch == 'D')
		flags->spec = d;
	else if (ch == 'o' || ch == 'O')
		flags->spec = o;
	else if (ch == 'x')
		flags->spec = x;
	else if (ch == 'u' || ch == 'U')
		flags->spec = u;
	else if (ch == 'c' || ch == 'C')
		flags->spec = c;
	else if (ch == 's')
		flags->spec = s;
	else if (ch == 'S')
		flags->spec = scaps;
	else if (ch == '%')
		flags->spec = pc;
	else if (ch == 'p')
		flags->spec = p;
	else if (ch == 'i')
		flags->spec = i;
	else if (ch == 'X')
		flags->spec = xcaps;
}

int		process(va_list ap, char *format, int *size)
{
	char	*add;
	char	*str;
	t_flags	*flags;
	int		diff;

	flags = init_flags();
	str = get_flags(format + 1, flags);
	spec(flags, *str);
	add = find_type(ap, str, flags);
	if (flags->spec == s || flags->spec == NON || flags->spec == scaps)
		change_str(&add, flags);
	else
		apply_format(&add, flags);
	ft_put_str(add, flags->cur);
	*size += flags->cur;
	diff = ft_strlen(format) - ft_strlen(str);
	free(add);
	free_flags(&flags);
	return (diff);
}

int		ft_printf(char *format, ...)
{
	va_list	ap;
	int		format_size;
	int		size;
	int		i;

	i = 0;
	size = 0;
	format_size = (int)ft_strlen(format);
	va_start(ap, format);
	while (format[i] != '\0' && i < format_size)
	{
		if (format[i] == '%')
			i += process(ap, format + i, &size);
		else
		{
			ft_putchar(format[i]);
			size++;
		}
		i++;
	}
	va_end(ap);
	return (size);
}
