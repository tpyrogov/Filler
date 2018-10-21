/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpyrogov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/25 17:53:06 by tpyrogov          #+#    #+#             */
/*   Updated: 2018/08/25 17:53:08 by tpyrogov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	cut(char **s, t_flags *flags)
{
	char	*save;
	int		i;

	i = 0;
	save = ft_strdup(*s);
	free(*s);
	*s = ft_strnew(flags->precision);
	while (i < flags->precision)
	{
		*((*s) + i) = *(save + i);
		i++;
	}
	flags->cur = flags->precision;
	free(save);
}

void	cut_scaps(char **s, t_flags *flags)
{
	char	*save;
	int		i;
	int		diff;

	i = 0;
	if (flags->counter > 0)
	{
		diff = flags->precision / flags->counter;
		save = ft_strdup(*s);
		free(*s);
		*s = ft_strnew(flags->precision);
		while (i < flags->counter * diff)
		{
			*((*s) + i) = *(save + i);
			i++;
		}
		flags->cur = flags->counter * diff;
		free(save);
	}
}

int		is_zero(char *str)
{
	while (*str != '\0')
	{
		if (*str != '0')
			return (0);
		str++;
	}
	return (1);
}

void	hash_hex(char **s, int hash, t_flags *flags)
{
	char *save;

	save = ft_strdup(*s);
	if (!is_zero(*s))
	{
		flags->cur += 2;
		free(*s);
		if (hash == 1)
			*s = ft_stradd("0x", save, 2, flags->cur);
		else
			*s = ft_stradd("0X", save, 2, flags->cur);
	}
	else if (flags->spec == p)
	{
		flags->cur += 2;
		free(*s);
		*s = ft_stradd("0x", save, 2, flags->cur);
	}
	free(save);
}

void	free_all(char **s, char **b)
{
	free(*s);
	free(*b);
}
