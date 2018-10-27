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

#include "includes/libft.h"

t_line	*new_fd(int fd)
{
	t_line *new;

	new = (t_line *)malloc(sizeof(t_line));
	new->fd = fd;
	new->rd = 0;
	new->next = NULL;
	new->str = NULL;
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

int		cut_line(char **line, t_line **cur, char *pos)
{
	size_t	size;
	char	*buff;

	size = (pos - (*cur)->str);
	if (!(*line = (char *)malloc(sizeof(char) * (size + 1))))
		return (-1);
	ft_strncpy(*line, (*cur)->str, size);
	(*line)[size] = '\0';
	(*cur)->rd -= (size + 1);
	if ((*cur)->rd != 0)
	{
		if (!(buff = (char *)malloc(sizeof(char) * (*cur)->rd + 1)))
			return (-1);
		ft_strncpy(buff, (*cur)->str + size + 1, (size_t)(*cur)->rd);
		free((*cur)->str);
		(*cur)->str = buff;
		buff[(*cur)->rd] = '\0';
	}
	else
	{
		free((*cur)->str);
		(*cur)->str = NULL;
	}
	return (1);
}

int		read_line(t_line **cur)
{
	ssize_t	rd;
	char	*buff;

	if (!(*cur)->str)
		(*cur)->str = malloc(BUFF_SIZE);
	if (!(buff = (char *)malloc(sizeof(char) * (BUFF_SIZE + (*cur)->rd + 1))))
		return (-1);
	if ((*cur)->rd > 0)
		ft_strncpy(buff, (*cur)->str, (size_t)(*cur)->rd);
	free((*cur)->str);
	(*cur)->str = buff;
	if ((rd = read((*cur)->fd, buff + (*cur)->rd, BUFF_SIZE)) < 0)
		return (-1);
	(*cur)->rd += rd;
	buff[(*cur)->rd] = '\0';
	if (rd > 0)
		return (1);
	return ((int)rd);
}

int		get_next_line(const int fd, char **line)
{
	static t_line	*files = NULL;
	t_line			*cur;
	char			*pos;
	int				end;

	if (fd >= 0 && line != NULL && (cur = get_file(&files, fd)))
	{
		*line = 0;
		if ((pos = ft_memchr(cur->str, '\n', cur->rd)))
			return (cut_line(line, &cur, pos));
		while ((end = read_line(&cur) > 0))
			if ((pos = ft_memchr(cur->str, '\n', cur->rd)))
				return (cut_line(line, &cur, pos));
		if (end < 0)
			return (-1);
		else if (end == 0 && cur->rd == 0)
			return (0);
		*line = ft_strsub(cur->str, 0, cur->rd + 1);
		cur->str = NULL;
		cur->rd = 0;
	}
	else
		return (-1);
	return (1);
}
