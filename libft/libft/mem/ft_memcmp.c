/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikgarci <mikgarci@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 14:49:20 by mikgarci          #+#    #+#             */
/*   Updated: 2021/09/23 16:29:39 by mikgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s1_2;
	unsigned char	*s2_2;
	unsigned int	i;

	s1_2 = (unsigned char *) s1;
	s2_2 = (unsigned char *) s2;
	i = 0;
	while (i < n && s1_2 && s2_2 && s1_2[i] == s2_2[i])
		i++;
	if (i == n)
		return (0);
	return (s1_2[i] - s2_2[i]);
}
