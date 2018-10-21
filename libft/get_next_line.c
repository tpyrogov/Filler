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

t_line	*new_fd(int fd)
{
	t_line *new;

	new = (t_line *)malloc(sizeof(t_line));
	new->fd = fd;
	new->next = NULL;
	new->str = ft_strnew(BUFF_SIZE);
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
	char	*save;
	char	*w;

	w = ft_strdup((*cur)->str);
	while (!(ft_strchr(w, '\n'))
		&& (rd = read((*cur)->fd, buff, BUFF_SIZE)))
	{
		buff[rd] = '\0';
		save = ft_strdup(w);
		free(w);
		if (rd == -1 || !(w = ft_strjoin(save, buff)))
			return (-1);
		free(save);
	}
	if (rd < BUFF_SIZE && !ft_strlen(w))
	{
		free(w);
		return (0);
	}
	(rd = ft_writetil(line, w, '\n')) < (int)ft_strlen(w) ?
	(*cur)->str = ft_strcpy((*cur)->str, w + rd + 1) : ft_strclr((*cur)->str);
	free(w);
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
			return (0);
	}
	else
		return (-1);
	return (1);
}

