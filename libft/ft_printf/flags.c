/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpyrogov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/25 17:48:17 by tpyrogov          #+#    #+#             */
/*   Updated: 2018/08/25 17:52:37 by tpyrogov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	plus(char **s, t_flags *flags)
{
	char *save;

	save = ft_strdup(*s);
	free(*s);
	if (flags->neg == 0)
		*s = ft_stradd("+", save, 1, flags->cur);
	else
		*s = ft_stradd("-", save, 1, flags->cur);
	flags->cur++;
	free(save);
}

void	zero(char **s, int width, t_flags *flags)
{
	int		size;
	char	*save;
	char	*zero;

	size = width - flags->cur;
	if (size > 0)
	{
		save = ft_strdup(*s);
		free(*s);
		ft_fill_new(&zero, size, '0');
		*s = ft_stradd(zero, save, size, flags->cur);
		flags->cur += size;
		free(save);
		free(zero);
	}
}

void	space(char **s, t_flags *flags)
{
	int		size;
	char	*save;
	char	*space;

	size = flags->width - flags->cur;
	if (size > 0)
	{
		save = ft_strdup(*s);
		free(*s);
		ft_fill_new(&space, size, ' ');
		if (flags->minus == 1)
			*s = ft_stradd(save, space, flags->cur, size);
		else
			*s = ft_stradd(space, save, size, flags->cur);
		flags->cur += size;
		free(save);
		free(space);
	}
}

void	space_before(char **s, t_flags *flags)
{
	char *save;

	if (**s != '-' && **s != '+')
	{
		save = ft_strdup(*s);
		free(*s);
		*s = ft_stradd(" ", save, 1, flags->cur);
		flags->cur++;
		free(save);
	}
}

void	hash(char **s, t_flags *flags)
{
	char *save;

	save = ft_strdup(*s);
	flags->cur += 1;
	if (ft_atoi(save) != 0)
	{
		free(*s);
		*s = ft_stradd("0", save, 1, flags->cur);
	}
	else
	{
		free(*s);
		*s = ft_stradd("0", save, 1, 0);
		flags->cur = 1;
	}
	free(save);
}
