/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikgarci <mikgarci@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 17:35:55 by mikgarci          #+#    #+#             */
/*   Updated: 2021/09/22 19:22:19 by mikgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdlib.h>

static int	ft_contword(char const *s, char c)
{
	int	len;
	int	cont;

	len = 0;
	cont = 0;
	while (cont < (int) ft_strlen(s))
	{
		if (s[cont] == c && s[cont - 1] != c)
			len++;
		cont++;
	}
	return (len + 1);
}

static char	**ft_table(int i, char **table)
{
	int	j;

	j = i;
	while (--i >= 0)
	{
		if (!table[i])
		{
			while (--j >= 0)
				free(table[j]);
			free(table);
			return (NULL);
		}
	}
	return (table);
}

static char	**ft_malloctable(char const *s, char c, char **table)
{
	int	cont;
	int	len;
	int	i;

	len = 0;
	cont = 0;
	i = 0;
	while (s[cont])
	{
		if (s[cont] == c || s[cont + 1] == '\0')
		{
			if (s[cont + 1] == '\0' && s[cont] != c)
				table[i++] = ft_substr(s, cont - len, len + 1);
			else if (len != 0)
				table[i++] = ft_substr(s, cont - len, len);
			len = -1;
		}
		cont++;
		len++;
	}
	table[i] = NULL;
	table = ft_table(i, table);
	return (table);
}

char	**ft_split(char const *s, char c)
{
	char	**table;

	if (!s)
		return (NULL);
	table = (char **) malloc (ft_contword(s, c) * sizeof(char *) + 1);
	if (!table)
		return (NULL);
	ft_malloctable(s, c, table);
	return (table);
}
