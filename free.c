//
// Created by Tania PYROGOVSKA on 10/18/18.
//

#include "filler.h"

void	free_map(t_data *game)
{
	int i;

	i = 0;
	while (i < game->m_h)
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
	game->map = NULL;
}

void	free_piece(t_data *game)
{
	int i;

	i = 0;
	while (i < game->p_h)
	{
		free(game->piece[i]);
		i++;
	}
	free(game->piece);
	game->piece = NULL;
}


void	del_before_update(t_data *game)
{
	free_map(game);
	free_piece(game);
	game->sum = 0;
	game->ans_x = -1;
	game->ans_y = -1;
	game->p_w = -1;
	game->p_h = -1;
}