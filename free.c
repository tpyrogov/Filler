//
// Created by Tania PYROGOVSKA on 10/18/18.
//

#include "filler.h"

void	free_mass(unsigned char **mass, int max)
{
	int i;

	i = 0;
	while (i < max)
	{
		free(mass[i]);
		i++;
	}
	free(mass);
}

void	free_data(t_data *game)
{
	if (game->map != NULL)
		free_mass(game->map, game->m_h);
	game->map = NULL;
	if (game->piece != NULL)
		free_mass(game->piece, game->p_h);
	game->piece = NULL;
}

void	del_before_update(t_data *game)
{
	free_data(game);
	game->sum = 0;
	game->ans_x = -1;
	game->ans_y = -1;
	game->p_w = -1;
	game->p_h = -1;
}