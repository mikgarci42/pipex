/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikgarci <mikgarci@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 14:58:35 by mikgarci          #+#    #+#             */
/*   Updated: 2021/09/23 16:34:56 by mikgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	cont;

	i = ft_strlen(dst);
	j = ft_strlen(dst);
	if (dstsize - j == 0 || dstsize < j)
		return (ft_strlen(src) + dstsize);
	cont = 0;
	while ((dstsize - j - 1) > cont && src[cont])
	{
		dst[i] = src[cont];
		cont++;
		i++;
	}
	dst[i] = '\0';
	return (j + ft_strlen(src));
}
