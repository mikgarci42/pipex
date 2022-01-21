/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikgarci <mikgarci@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 14:33:31 by mikgarci          #+#    #+#             */
/*   Updated: 2021/09/23 16:29:25 by mikgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*srch;
	unsigned char	po;
	unsigned int	i;

	srch = (unsigned char *) s;
	po = (unsigned char) c;
	i = 0;
	while (i < n)
	{
		if (srch[i] == po)
			return ((void *)srch + i);
		i++;
	}
	return (NULL);
}
