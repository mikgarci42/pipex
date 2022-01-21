/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikgarci <mikgarci@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 14:28:34 by mikgarci          #+#    #+#             */
/*   Updated: 2021/09/23 16:30:06 by mikgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	if (dst < src)
		return (ft_memcpy(dst, src, len));
	if (!len || dst == (void *) src)
		return (dst);
	while (len--)
		((unsigned char *)dst)[len] = ((unsigned char *)src)[len];
	return (dst);
}
