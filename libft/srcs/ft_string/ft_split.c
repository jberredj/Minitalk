/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberredj <jberredj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 10:56:03 by jberredj          #+#    #+#             */
/*   Updated: 2021/08/16 12:54:47 by jberredj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

static size_t	ft_strlen_sep(const char *str, char sep)
{
	size_t	i;

	i = 0;
	while (*str == sep)
		str++;
	while (str[i] != sep && str[i] != '\0')
		i++;
	return (i);
}

void	*ft_free_split(char **tab, size_t index)
{
	size_t	i;

	i = 0;
	while (i < index)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

size_t	ft_split_size(char **tab)
{
	size_t	size;

	size = 0;
	while (tab[size] != NULL)
		size++;
	return (size);
}

char	**ft_split(char const *s, char c)
{
	size_t	tab_size;
	size_t	i;
	size_t	str_len;
	char	**tab;

	tab_size = ft_cw_sep(s, c);
	tab = (char **)ft_calloc(sizeof(char *), (tab_size + 1));
	if (tab == NULL)
		return (NULL);
	i = 0;
	while (i < tab_size)
	{
		while (*s == c)
			s++;
		str_len = ft_strlen_sep(s, c);
		tab[i] = ft_substr(s, 0, str_len);
		if (tab[i] == NULL)
			return (ft_free_split(tab, i));
		s += str_len;
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
