/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpyrogov <tpyrogov@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 17:59:28 by tpyrogov          #+#    #+#             */
/*   Updated: 2018/10/22 17:59:30 by tpyrogov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		check_condiotions(t_data *game, int i, int j, int *first)
{
	if (game->piece[i][j] == '*'
		&& game->map[game->temp_y + i][game->temp_x + j] == game->me)
	{
		if (*first == 1)
			*first = 0;
		else
			return (-1);
	}
	else if (game->piece[i][j] == '*'
		&& game->map[game->temp_y + i][game->temp_x + j] == game->enemy)
		return (-1);
	if (game->map[game->temp_y + i][game->temp_x + j] == game->me)
		return (0);
	return (game->map[game->temp_y + i][game->temp_x + j]);
}

int		validate_coords(t_data *game, int i, int j)
{
	if (i >= 0 && i < game->m_h && j >= 0 && j < game->m_w)
		return (1);
	return (0);
}

void	mark_players(t_data *game)
{
	int i;
	int j;

	i = 0;
	while (i < game->m_h)
	{
		j = 0;
		while (j < game->m_w)
		{
			if (game->map[i][j] == 'X'
			|| game->map[i][j] == 'x')
				game->map[i][j] = 224;
			else if (game->map[i][j] == 'O'
			|| game->map[i][j] == 'o')
				game->map[i][j] = 223;
			j++;
		}
		i++;
	}
}

void	get_num(int *height, int *width, char *s)
{
	while (!ft_isdigit(*s))
		s++;
	*height = ft_atoi(s);
	s += ft_count_digits(*height);
	*width = ft_atoi(s);
}
