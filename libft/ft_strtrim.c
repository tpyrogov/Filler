/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpyrogov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 14:50:57 by tpyrogov          #+#    #+#             */
/*   Updated: 2017/11/08 14:50:58 by tpyrogov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static int	ft_size_no_sp(char *s)
{
	int		size;
	int		i;
	int		j;

	i = 0;
	size = 0;
	j = ft_strlen(s) - 1;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	while (s[j] == ' ' || s[j] == '\n' || s[j] == '\t')
		j--;
	return (j - i + 1);
}

char		*ft_strtrim(char const *s)
{
	char	*res;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	if (s[i] != '\0')
	{
		if (!(res = (char *)malloc(ft_size_no_sp((char *)s) + 1)))
			return (NULL);
		while (j < ft_size_no_sp((char *)s))
			res[j++] = s[i++];
		res[j] = '\0';
	}
	else
	{
		if ((res = (char *)malloc(sizeof(char) * 1)))
			res[0] = '\0';
	}
	return (res);
}
