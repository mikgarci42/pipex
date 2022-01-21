/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikgarci <mikgarci@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 17:44:38 by mikgarci          #+#    #+#             */
/*   Updated: 2021/10/19 17:21:33 by mikgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_atoi(const char *str)
{
	int	cont;
	int	neg;
	int	reg;

	neg = 1;
	cont = 0;
	while (str[cont] == ' ' || (str[cont] >= 9 && str[cont] <= 13))
		cont++;
	if (str[cont] == '-' || str[cont] == '+')
	{
		if (str[cont] == '-')
			neg = -1;
		cont++;
	}
	reg = 0;
	while (str[cont] >= '0' && str[cont] <= '9')
	{
		reg = str[cont] - '0' + reg * 10;
		cont++;
	}
	return (reg * neg);
}
