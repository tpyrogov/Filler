#include <stdio.h>
#include "filler.h"

int 	validate_coords(t_data *game, int i, int j)
{
	if (i >= 0 && i < game->m_h && j >= 0 && j < game->m_w)
		return (1);
	return (0);
}

int 	check_condiotions(t_data *game, int i, int j, int *first)
{
	if (game->piece[i][j] == '*' && game->map[game->temp_y + i][game->temp_x + j] == game->me)
	{
		if(*first == 1)
			*first = 0;
		else
			return (-1);
	}
	else if (game->piece[i][j] == '*' && game->map[game->temp_y + i][game->temp_x + j] == game->enemy)
		return (-1);
//	if ((game->piece[i][j] == '.' && game->map[game->temp_y + i][game->temp_x + j] == game->me)
//	|| (game->piece[i][j] == '*' && game->map[game->temp_y + i][game->temp_x + j] == game->me))
//		return (0);
	return (game->map[game->temp_y + i][game->temp_x + j]);
}

int		fit(t_data *game)
{
	int i;
	int j;
	int first;
	int sum;
	int temp;

	sum = 0;
	first = 1;
	i = 0;
	while (i < game->p_h)
	{
		j = 0;
		while (j < game->p_w)
		{
			temp = check_condiotions(game, i, j, &first);
			if (temp != -1)
				sum += temp;
			else
				return (-1);
			j++;
		}
		i++;
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
		game->temp_x= j;
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

int 	solve(t_data *game)
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

int		main()
{
	t_data	game;
	int		cont;
//	FILE *fd;
//	int i, j;

//	fd = fopen("/Users/tpyrogov/CLionProjects/filler2/cmake-build-debug/file", "wr");
	cont = 1;
	start_init(&game);
	while (cont != -1)
	{
		if (init(&game) == -1)
			break;
		else
		{
//			i = 0;
//			fprintf(fd, "\n");
//			while (i < game.m_h)
//			{
//				j = 0;
//				while (j < game.m_w)
//				{
//					fprintf(fd, "%4d", game.map[i][j]);
//					j++;
//				}
//				fprintf(fd, "\n");
//				i++;
//			}
			cont = solve(&game);
			if (cont != -1)
			del_before_update(&game);
		}
	}
}