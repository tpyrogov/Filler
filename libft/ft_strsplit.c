/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpyrogov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 20:45:28 by tpyrogov          #+#    #+#             */
/*   Updated: 2017/11/07 20:45:29 by tpyrogov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include <stdio.h>

static int		ft_words(char const *str, char c)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c && str[i + 1] == c)
			count++;
		i++;
	}
	return (count + 1);
}

static int		ft_letters(const char *str, int i, char c)
{
	int count;

	count = 0;
	while (str[i] != c && str[i] != '\0')
	{
		count++;
		i++;
	}
	return (count);
}

static char		*write_to_string(const char *str, int start, char c)
{
	char	*s;
	int		i;

	i = 0;
	if (!(s = (char *)malloc(sizeof(char) * (ft_letters(str, start, c) + 1))))
		return (NULL);
	while (str[start] != c && str[start] != '\0')
	{
		s[i] = str[start];
		start++;
		i++;
	}
	s[i] = '\0';
	return (s);
}

static char		**ft_create_mass(char *s, char c)
{
	int		i;
	char	**mass;
	char	**head;

	if (!(mass = (char **)malloc(sizeof(char *) * (ft_words(s, c) + 2))))
		return (NULL);
	head = mass;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			*mass++ = write_to_string(s, i, c);
			if (*(mass - 1) == NULL)
			{
				ft_del_mas((void **)mass - ft_count_mass_el((void **)mass));
				return (mass);
			}
			i = i + ft_letters(s, i, c);
		}
		if (s[i] != '\0')
			i++;
	}
	*mass = 0;
	return (head);
}

char			**ft_strsplit(char const *s, char c)
{
	char **mass;

	if (s == NULL)
		return (NULL);
	mass = ft_create_mass((char *)s, c);
	return (mass);
}
