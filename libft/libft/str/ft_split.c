/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikgarci <mikgarci@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 17:22:22 by mikgarci          #+#    #+#             */
/*   Updated: 2021/10/19 17:23:15 by mikgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../libft.h"
#include <stdio.h>

static char	**ft_frlloc(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

static int	ft_strc(const char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] != c && str[i])
		i++;
	return (i);
}

static int	ft_tab_len(const char *s, char c)
{
	int	i;
	int	row;

	row = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != c && s[i] != 0)
			row++;
		while (s[i] != c && s[i])
			i++;
	}
	return (row);
}

static char	**ft_handle_tab(const char *str, char c, char **tab, int k)
{
	int	j;
	int	i;
	int	x;

	i = 0;
	j = 0;
	while (str[i] && j < k)
	{
		while (str[i] && str[i] == c)
			i++;
		if (str[i] != c)
		{
			x = ft_strc(str + i, c);
			tab[j] = ft_substr(str, i, x);
			if (tab[j] == NULL)
				return (ft_frlloc(tab));
			j++;
			tab[j] = NULL;
		}
		while (str[i] && str[i] != c)
			i++;
	}
	return (tab);
}

char	**ft_split(const char *s, char c)
{
	int		j;
	char	**tab;

	if (!s)
		return (NULL);
	j = ft_tab_len(s, c);
	tab = (char **)malloc((j + 1) * (sizeof(char *)));
	if (!tab)
		return (NULL);
	tab[j] = NULL;
	if (!j)
		return (tab);
	return (ft_handle_tab(s, c, tab, j));
}
