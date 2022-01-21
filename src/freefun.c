/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freefun.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikgarci <mikgarci@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 01:22:51 by mikgarci          #+#    #+#             */
/*   Updated: 2021/10/20 18:24:36 by mikgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"
#include <stdlib.h>

int	ft_freelist(t_data *info)
{
	int	cont;

	cont = -1;
	while (info->list[++cont])
		free(info->list[cont]);
	free(info->list);
	return (1);
}

int	ft_freepipes(t_data *info, int a)
{
	int	cont;

	cont = -1;
	while (++cont < a)
		free(info->pipes[cont]);
	free(info->pipes);
	return (1);
}
