/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpyrogov <tpyrogov@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 18:04:11 by tpyrogov          #+#    #+#             */
/*   Updated: 2018/10/22 18:04:15 by tpyrogov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		fit(t_data *game)
{
	t_coord	p;
	int		first;
	int		sum;
	int		temp;

	sum = 0;
	first = 1;
	p.y = 0;
	while (p.y < game->p_h)
	{
		p.x = 0;
		while (p.x < game->p_w)
		{
			temp = check_condiotions(game, p.y, p.x, &first);
			if (temp != -1)
				sum += temp;
			else
				return (-1);
			p.x++;
		}
		p.y++;
	}
	if (first == 1)
		return (-1);
	return (sum);
}

void	fit_again(t_data *game, int i, int j)
{
	int sum;

	if (validate_coords(game, i + game->p_h - 1, j + game->p_w - 1))
	{
		game->temp_x = j;
		game->temp_y = i;
		sum = fit(game);
		if ((sum < game->sum || game->sum == 0) && sum > 0)
		{
			game->sum = sum;
			game->ans_x = game->temp_x;
			game->ans_y = game->temp_y;
		}
	}
}

void	try_to_fit(t_data *game)
{
	int i;
	int j;

	i = 0;
	while (i < game->m_h)
	{
		j = 0;
		while (j < game->m_w)
		{
			fit_again(game, i, j);
			j++;
		}
		i++;
	}
}

int		solve(t_data *game)
{
	try_to_fit(game);
	if (game->ans_x == -1 || game->ans_y == -1)
	{
		ft_printf("%d %d\n", 0, 0);
		return (-1);
	}
	ft_printf("%d %d\n", game->ans_y, game->ans_x);
	return (1);
}

int		main(void)
{
	t_data game;

	start_init(&game);
	while (get_next_line(0, &game.read) > 0)
	{
		if (init(&game) == -1)
			return (0);
		free(game.read);
	}
}
