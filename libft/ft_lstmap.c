/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpyrogov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 16:22:24 by tpyrogov          #+#    #+#             */
/*   Updated: 2017/11/08 16:22:26 by tpyrogov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new;
	t_list *head;
	t_list *buf;

	head = NULL;
	if (lst && f)
	{
		buf = (*f)(lst);
		new = ft_lstnew(buf->content, buf->content_size);
		lst = lst->next;
		head = new;
		while (lst)
		{
			buf = (*f)(lst);
			new->next = ft_lstnew(buf->content, buf->content_size);
			lst = lst->next;
			new = new->next;
		}
	}
	return (head);
}
