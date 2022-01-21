/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikgarci <mikgarci@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 17:43:04 by mikgarci          #+#    #+#             */
/*   Updated: 2021/09/23 16:35:53 by mikgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int	pos;
	int	cont;

	pos = -1;
	cont = 0;
	while (str[cont])
	{
		if (str[cont] == (unsigned char) c)
			pos = cont;
		cont++;
	}
	if (c == 0)
		return ((char *) str + cont);
	if (!str[cont] && pos == -1)
		return (NULL);
	return ((char *) str + pos);
}
