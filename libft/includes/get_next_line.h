/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpyrogov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 16:02:29 by tpyrogov          #+#    #+#             */
/*   Updated: 2018/05/01 16:02:31 by tpyrogov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_GET_NEXT_LINE_H
# define GET_NEXT_LINE_GET_NEXT_LINE_H
# define BUFF_SIZE 10000

# include "libft.h"

typedef struct		s_line{
	int				fd;
	char			*str;
	struct s_line	*next;
}					t_line;

int					get_next_line(const int fd, char **line);

#endif
