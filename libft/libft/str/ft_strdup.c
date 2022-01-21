/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikgarci <mikgarci@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 17:50:20 by mikgarci          #+#    #+#             */
/*   Updated: 2021/09/23 16:34:40 by mikgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	char	*dest;
	int		cont;

	dest = (char *) malloc(ft_strlen(s1) * sizeof(char) + 1);
	if (!dest)
		return (NULL);
	cont = 0;
	while (s1[cont])
	{
		dest[cont] = s1[cont];
		cont++;
	}
	dest[cont] = '\0';
	return (dest);
}
