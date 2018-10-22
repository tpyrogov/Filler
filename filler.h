//
// Created by Tania PYROGOVSKA on 9/6/18.
//

#ifndef FILLER_H
#define FILLER_H

#include "libft/includes/libft.h"

typedef struct		s_data
{
	unsigned char	**map;
	unsigned char	**piece;
	int				m_h;
	int				m_w;
	int				p_h;
	int				p_w;
	int				sum;
	int				temp_x;
	int 			temp_y;
	unsigned char	enemy;
	unsigned char	me;
	int				ans_x;
	int				ans_y;
	int 			init;
	char			*read;

}					t_data;

typedef struct		s_coord
{
	int				x;
	int 			y;
}					t_coord;

int 	init(t_data *game);
void	start_init(t_data *game);

void	init_players(t_data *game);
int		init_board(t_data *game);
int 	init_piece(t_data *game);

void	distance_map(t_data *game);

void	del_before_update(t_data *game);
void	free_data(t_data *game);
void	free_mass(unsigned char **mass, int max);

#endif //FILLER2_FILLER_H
