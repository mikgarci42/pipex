/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikgarci <mikgarci@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 17:00:34 by mikgarci          #+#    #+#             */
/*   Updated: 2021/09/23 16:27:16 by mikgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdlib.h>

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*buf;

	if (!lst)
		return ;
	while (*lst)
	{
		buf = *lst;
		del((*lst)->content);
		free(*lst);
		(*lst) = buf->next;
	}
	lst = NULL;
}
