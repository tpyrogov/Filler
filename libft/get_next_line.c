/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpyrogov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 16:00:34 by tpyrogov          #+#    #+#             */
/*   Updated: 2018/05/01 16:00:36 by tpyrogov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/get_next_line.h"

void	del_file(t_line **files, t_line *cur)
{
	t_line *next;

	next = *files;
	while (next)
	{
		if (next->next->fd == cur->fd)
		{
			ft_strdel(&cur->str);
			next->next = cur->next;
			free(cur);
		}
		next = next->next;
	}
}

t_line	*new_fd(int fd)
{
	t_line *new;

	new = (t_line *)malloc(sizeof(t_line));
	new->fd = fd;
	new->next = NULL;
	new->str = ft_strnew(BUFF_SIZE);
	new->w = ft_strnew(BUFF_SIZE);
	new->save = ft_strnew(BUFF_SIZE);
	return (new);
}

t_line	*get_file(t_line **files, int fd)
{
	t_line *cur;

	cur = *files;
	while (cur)
	{
		if (cur->fd == fd)
			return (cur);
		cur = cur->next;
	}
	cur = new_fd(fd);
	cur->next = *files;
	*files = cur;
	return (cur);
}

int		read_line(t_line **cur, char **line)
{
	int		rd;
	char	buff[BUFF_SIZE + 1];

	(*cur)->w = ft_strdup((*cur)->str);
	while (!(ft_strchr((*cur)->w, '\n'))
		&& (rd = read((*cur)->fd, buff, BUFF_SIZE)))
	{
		buff[rd] = '\0';
		(*cur)->save = ft_strdup((*cur)->w);
//		free((*cur)->w);
		if (rd == -1 || !((*cur)->w = ft_strjoin((*cur)->save, buff)))
			return (-1);
		ft_strdel(&(*cur)->save);
	}
	if (rd < BUFF_SIZE && !ft_strlen((*cur)->w))
	{
		ft_strdel(&(*cur)->w);
		return (0);
	}
	(rd = ft_writetil(line, (*cur)->w, '\n')) < (int)ft_strlen((*cur)->w) ?
	(*cur)->str = ft_strcpy((*cur)->str, (*cur)->w + rd + 1) : ft_strclr((*cur)->str);
	ft_strdel(&(*cur)->w);
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static t_line	*files = NULL;
	t_line			*cur;
	int				end;

	if (fd >= 0 && line != NULL)
	{
		cur = get_file(&files, fd);
		end = read_line(&cur, line);
		if (end == -1)
			return (-1);
		else if (end == 0)
		{
//			del_file(&files, cur);
			return (0);
		}
	}
	else
		return (-1);
	return (1);
}

