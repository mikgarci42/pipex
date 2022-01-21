/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikgarci <mikgarci@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 17:44:12 by mikgarci          #+#    #+#             */
/*   Updated: 2021/10/19 17:23:29 by mikgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	a;

	if (n == 0)
		return (0);
	a = 0;
	while (a < n)
	{
		if ((unsigned char) s1[a] - (unsigned char) s2[a] < 0)
			return (-1);
		if ((unsigned char) s1[a] - (unsigned char) s2[a] > 0)
			return (1);
		a++;
		if ((unsigned char) s1[a] == '\0' && (unsigned char) s2[a] == '\0')
			return (0);
	}
	return (0);
}
