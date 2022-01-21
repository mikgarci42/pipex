/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikgarci <mikgarci@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 17:43:40 by mikgarci          #+#    #+#             */
/*   Updated: 2021/09/23 16:35:54 by mikgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strnstr( const char *str, const char *need, size_t len)
{
	unsigned int	a;
	unsigned int	b;
	unsigned int	c;

	c = 0;
	a = 0;
	if (*need == '\0')
		return ((char *) str);
	while ((char)str[a] && a < len)
	{
		b = 0;
		if ((char)str[a] == need[b])
		{
			c = a;
			while ((char)str[c] == need[b] && need[b] && c < len)
			{
				b++;
				c++;
			}
			if (need[b] == '\0')
				return ((char *)str + a);
		}
		a++;
	}
	return (NULL);
}
