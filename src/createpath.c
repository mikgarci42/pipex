/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   createpath.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikgarci <mikgarci@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 19:48:59 by mikgarci          #+#    #+#             */
/*   Updated: 2021/10/21 17:53:43 by mikgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"
#include <stdlib.h>

void	ft_splitenve(char **envp, t_data *info)
{
	int		cont;
	char	*str;

	cont = 0;
	while (envp[cont])
	{
		if (ft_strnstr((const char *)envp[cont],
				"PATH=", ft_strlen((const char *)envp[cont])))
		{
			str = ft_substr(envp[cont], 5, ft_strlen(envp[cont]));
			info->list = ft_split(str, ':');
			free(str);
			return ;
		}
		cont++;
	}
}

void	ft_complenve(t_data *info)
{
	char	*temp;
	int		cont;

	cont = 0;
	while (info->list[cont])
	{
		temp = ft_strjoin(info->list[cont], "/");
		if (!temp)
		{
			cont = -1;
			while (info->list[++cont])
				free(info->list[cont]);
			free(info->list);
			return ;
		}
		free(info->list[cont]);
		info->list[cont] = temp;
		cont++;
	}
}
