/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikgarci <mikgarci@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 15:31:26 by mikgarci          #+#    #+#             */
/*   Updated: 2021/09/23 16:36:13 by mikgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*dest;
	unsigned int	cont;

	dest = (char *) malloc(len * sizeof(char) + 1);
	if (!s)
		return (NULL);
	if (!dest)
		return (NULL);
	cont = 0;
	if (start > ft_strlen(s))
	{
		dest[cont] = '\0';
		return (dest);
	}
	while (cont < len)
	{
		dest[cont] = s[start];
		cont++;
		start++;
	}
	dest[cont] = '\0';
	return (dest);
}
