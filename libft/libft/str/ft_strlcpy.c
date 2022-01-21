/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikgarci <mikgarci@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 14:58:15 by mikgarci          #+#    #+#             */
/*   Updated: 2021/09/23 16:35:11 by mikgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	cont;

	if (!src)
		return (0);
	i = ft_strlen(dst);
	j = ft_strlen(src);
	if (dstsize == 0)
		return (j);
	cont = 0;
	while ((dstsize - 1) > cont && src[cont])
	{
		dst[cont] = src[cont];
		cont++;
	}
	dst[cont] = '\0';
	return (j);
}
