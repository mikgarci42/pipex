/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikgarci <mikgarci@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 17:49:41 by mikgarci          #+#    #+#             */
/*   Updated: 2021/09/23 16:29:12 by mikgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	void	*dest;

	dest = (void *) malloc(count * size);
	if (!dest)
		return (NULL);
	ft_memset(dest, 0, count * size);
	return (dest);
}
