/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikgarci <mikgarci@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 18:44:32 by mikgarci          #+#    #+#             */
/*   Updated: 2021/09/23 16:35:28 by mikgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*dst;
	unsigned int	cont;

	if (!s)
		return (NULL);
	dst = (char *) malloc(ft_strlen(s) * sizeof(char) + 1);
	if (!dst)
		return (NULL);
	cont = 0;
	while (cont < ft_strlen(s))
	{
		dst[cont] = f(cont, s[cont]);
		cont++;
	}
	dst[cont] = '\0';
	return (dst);
}
