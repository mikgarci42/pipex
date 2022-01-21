/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikgarci <mikgarci@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 15:23:01 by mikgarci          #+#    #+#             */
/*   Updated: 2021/09/23 16:36:14 by mikgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdlib.h>

static int	ft_compare(char c, char *s2)
{
	int	cont;

	cont = 0;
	while (s2[cont])
	{
		if (s2[cont] == c)
			return (1);
		cont++;
	}
	return (0);
}

static int	ft_separe(int end, char const *s1, char const *s2)
{
	while (s1[end])
	{
		if (ft_compare((char) s1[end], (char *) s2) == 0)
			break ;
		end--;
	}
	return (end);
}

char	*ft_strtrim(char const *s1, const char *s2)
{
	int				cont;
	unsigned int	start;
	unsigned int	end;
	char			*dst;

	if (!s1)
		return (NULL);
	start = 0;
	cont = 0;
	while ((char) s1[cont])
	{
		if (ft_compare((char) s1[cont], (char *) s2) == 0)
			break ;
		start++;
		cont++;
	}
	end = ft_strlen(s1) - 1;
	if (start == end + 1)
		return (ft_substr(s1, 0, 0));
	end = ft_separe(end, s1, s2);
	if (end <= 0)
		end = 1;
	dst = ft_substr(s1, start, end - start + 1);
	return (dst);
}
