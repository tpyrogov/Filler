/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpyrogov <tpyrogov@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 18:05:00 by tpyrogov          #+#    #+#             */
/*   Updated: 2018/10/22 18:05:02 by tpyrogov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	forward(t_data *game, int i, int *y, int *x)
{
	int j;

	while (i < game->m_h)
	{
		j = 0;
		while (j < game->m_w)
		{
			if (game->map[i][j] == game->enemy)
			{
				*y = i;
				*x = j;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	backward(t_data *game, int i, int *y, int *x)
{
	int j;

	while (i > 0)
	{
		j = game->m_w - 1;
		while (j > 0)
		{
			if (game->map[i][j] == game->enemy)
			{
				*y = i;
				*x = j;
				return ;
			}
			j--;
		}
		i--;
	}
}

int		ft_abs(int a)
{
	if (a < 0)
		return (a * (-1));
	return (a);
}

int		calc_distance(t_data *game, int i, int j)
{
	int enemy_x;
	int enemy_y;
	int dis1;

	forward(game, i, &enemy_y, &enemy_x);
	if (enemy_x != -1 && enemy_y != -1)
		dis1 = ft_abs(enemy_y - i) + ft_abs(enemy_x - j);
	else
	{
		backward(game, i, &enemy_y, &enemy_x);
		dis1 = ft_abs(enemy_y - i) + ft_abs(enemy_x - j);
	}
	return (dis1);
}

void	distance_map(t_data *game)
{
	int i;
	int j;

	i = 0;
	while (i < game->m_h)
	{
		j = 0;
		while (j < game->m_w)
		{
			if (game->map[i][j] == '.')
				game->map[i][j] = (unsigned char)calc_distance(game, i, j);
			j++;
		}
		i++;
	}
}
