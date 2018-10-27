/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpyrogov <tpyrogov@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 17:53:48 by tpyrogov          #+#    #+#             */
/*   Updated: 2018/10/22 17:53:50 by tpyrogov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	init_players(t_data *game)
{
	if (game->me == 0)
	{
		if ((ft_strstr(game->read, "p1")
		&& ft_strstr(game->read, "tpyrogov"))
		|| (ft_strstr(game->read, "p2")
		&& ft_strstr(game->read, "tpyrogov") == NULL))
		{
			game->me = (unsigned char)223;
			game->enemy = (unsigned char)224;
		}
		else
		{
			game->me = (unsigned char)224;
			game->enemy = (unsigned char)223;
		}
	}
}

int		init_board(t_data *game)
{
	int i;

	i = 0;
	free(game->read);
	get_next_line(0, &game->read);
	ft_strdel(&game->read);
	if (!(game->map = (unsigned char **)malloc(
		sizeof(unsigned char *) * game->m_h)))
		return (-1);
	while (i < game->m_h)
	{
		if (get_next_line(STDIN_FILENO, &game->read) > 0)
		{
			game->map[i] = (unsigned char *)ft_strdup(game->read + 4);
			ft_strdel(&game->read);
		}
		else
			return (-1);
		i++;
	}
	mark_players(game);
	return (1);
}

int		init_piece(t_data *game)
{
	int i;

	i = 0;
	free(game->read);
	if (!(game->piece = (unsigned char **)malloc(
		sizeof(unsigned char *) * game->p_h)))
		return (-1);
	while (i < game->p_h)
	{
		if (get_next_line(STDIN_FILENO, &game->read) > 0)
		{
			game->piece[i] = (unsigned char *)ft_strdup(game->read);
			ft_strdel(&game->read);
		}
		else
			return (-1);
		i++;
	}
	return (1);
}

void	start_init(t_data *game)
{
	game->map = NULL;
	game->piece = NULL;
	game->m_h = -1;
	game->m_w = -1;
	game->ans_x = -1;
	game->ans_y = -1;
	game->p_h = -1;
	game->p_w = -1;
	game->enemy = 0;
	game->me = 0;
	game->sum = 0;
}

int		init(t_data *game)
{
	if (ft_strstr(game->read, "$$$"))
		init_players(game);
	else if (ft_strstr(game->read, "Plateau"))
	{
		get_num(&game->m_h, &game->m_w, game->read);
		if (init_board(game) == -1)
			return (-1);
		distance_map(game);
	}
	else if (ft_strstr(game->read, "Piece"))
	{
		get_num(&game->p_h, &game->p_w, game->read);
		if (init_piece(game) == -1 || solve(game) == -1)
			return (-1);
		del_before_update(game);
	}
	else
		return (-1);
	return (1);
}
