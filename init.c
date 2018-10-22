//
// Created by Tania PYROGOVSKA on 9/6/18.
//
#include "filler.h"

void	get_num(int *height, int *width, char *s)
{
	while (!ft_isdigit(*s))
		s++;
	*height = ft_atoi(s);
	s += ft_count_digits(*height);
	*width = ft_atoi(s);
}

void	init_players(t_data *game)
{
	if (game->me == 0)
	{
		if ((ft_strstr(game->read, "p1") && ft_strstr(game->read, "tpyrogov")) ||
		(ft_strstr(game->read, "p2") && ft_strstr(game->read, "tpyrogov") == NULL))
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

int		init_board(t_data *game)
{
	int i;

	i = 0;
	get_next_line(STDIN_FILENO, &game->read);
	ft_strdel(&game->read);
	if (!(game->map = (unsigned char **)malloc(sizeof(unsigned char *) * game->m_h)))
		return (-1);
	while (i < game->m_h)
	{
		if (get_next_line(STDIN_FILENO, &game->read) != -1)
		{
			game->map[i] = (unsigned char *)ft_strsub(game->read, 4, (size_t)game->m_w);
			ft_strdel(&game->read);
		}
		i++;
	}
	mark_players(game);
	return (1);
}

int 	init_piece(t_data *game)
{
	int i;

	i = 0;
	if (!(game->piece = (unsigned char **)malloc(sizeof(unsigned char *) * game->p_h)))
		return (-1);
	while (i < game->p_h)
	{
		if (get_next_line(STDIN_FILENO, &game->read) != -1)
		{
			game->piece[i] = (unsigned char *) ft_strdup(game->read);
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
	game->read = NULL;
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
	game->init = 1;
}

int 	init(t_data *game)
{
	int end;

	end = 1;
	while (end != 0 && get_next_line(STDIN_FILENO, &game->read) > 0)
	{
		if (ft_strstr(game->read, "$$$"))
			init_players(game);
		else if (ft_strstr(game->read, "Plateau"))
		{
			get_num(&game->m_h, &game->m_w, game->read);
			init_board(game);
			distance_map(game);
		}
		else if (ft_strstr(game->read, "Piece"))
		{
			get_num(&game->p_h, &game->p_w, game->read);
			init_piece(game);
			end = 0;
		}
		else
			return (-1);
		ft_strdel(&game->read);
	}
	return (1);
}
