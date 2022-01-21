/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikgarci <mikgarci@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 14:05:22 by mikgarci          #+#    #+#             */
/*   Updated: 2021/09/23 16:30:07 by mikgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_bzero(void *str, size_t n)
{
	unsigned int	i;
	unsigned char	*str2;

	str2 = str;
	i = 0;
	if (n == 0)
		return ;
	while (i < n)
	{
		str2[i] = '\0';
		i++;
	}
}
