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
	char *s;

	s = NULL;
	get_next_line(STDIN_FILENO, &s);
	if (game->me == 0)
	{
		if ((ft_strstr(s, "p1") && ft_strstr(s, "tpyrogov")) ||
		(ft_strstr(s, "p2") && ft_strstr(s, "tpyrogov") == NULL))
		{
			game->me = 223;
			game->enemy = 224;
		}
		else
		{
			game->me = 224;
			game->enemy = 223;
		}
	}
	ft_strdel(&s);
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
	char *str;

	i = 0;
	str = NULL;
	get_next_line(STDIN_FILENO, &str);
	ft_strdel(&str);
	if (!(game->map = (unsigned char **)malloc(sizeof(unsigned char *) * game->m_h)))
		return (-1);
	while (i < game->m_h)
	{
		if (get_next_line(STDIN_FILENO, &str) != -1)
		{
			game->map[i] = (unsigned char *) ft_strdup(str + 4);
			ft_strdel(&str);
		}
		i++;
	}
	mark_players(game);
	return (1);
}

int 	init_piece(t_data *game)
{
	int i;
	char *str;

	i = 0;
	str = NULL;
	if (!(game->piece = (unsigned char **)malloc(sizeof(unsigned char *) * game->p_h)))
		return (-1);
	while (i < game->p_h)
	{
		if (get_next_line(STDIN_FILENO, &str) != -1)
		{
			game->piece[i] = (unsigned char *) ft_strdup(str);
			ft_strdel(&str);
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

int 	init(t_data *game)
{
	char *s;

	s = NULL;
	get_next_line(STDIN_FILENO, &s);
	if (ft_strstr(s, "Plateau"))
	{
		get_num(&game->m_h, &game->m_w, s);
		if (init_board(game) == -1)
			return (-1);
	}
	ft_strdel(&s);
	get_next_line(STDIN_FILENO, &s);
	if (ft_strstr(s, "Piece"))
	{
		get_num(&game->p_h, &game->p_w, s);
		if (init_piece(game) == -1)
			return (-1);
	}
	ft_strdel(&s);
	return (1);
}
