/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpyrogov <tpyrogov@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 17:42:14 by tpyrogov          #+#    #+#             */
/*   Updated: 2018/10/22 17:42:33 by tpyrogov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include "libft/includes/libft.h"

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
	int				temp_y;
	unsigned char	enemy;
	unsigned char	me;
	int				ans_x;
	int				ans_y;
	char			*read;

}					t_data;

typedef struct		s_coord
{
	int				x;
	int				y;
}					t_coord;

int					init(t_data *game);
void				start_init(t_data *game);

void				init_players(t_data *game);
int					init_board(t_data *game);
int					init_piece(t_data *game);

void				distance_map(t_data *game);
void				mark_players(t_data *game);
void				get_num(int *height, int *width, char *s);
int					check_condiotions(t_data *game, int i, int j, int *first);
int					validate_coords(t_data *game, int i, int j);
int					solve(t_data *game);

void				del_before_update(t_data *game);
void				free_data(t_data *game);
void				free_mass(unsigned char **mass, int max);

#endif
