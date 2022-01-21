/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikgarci <mikgarci@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 14:54:27 by mikgarci          #+#    #+#             */
/*   Updated: 2021/09/23 16:34:23 by mikgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	cont;

	cont = 0;
	while (s[cont])
	{
		if (s[cont] == (unsigned char) c)
			return ((char *) s + cont);
		cont++;
	}
	if (c == 0)
		return ((char *) s + ft_strlen(s));
	return (NULL);
}
