/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikgarci <mikgarci@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 17:54:23 by mikgarci          #+#    #+#             */
/*   Updated: 2021/09/23 16:34:40 by mikgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	char	*dest;
	size_t	len2;

	if (!s1 && !s2)
		return (ft_strdup(""));
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	dest = (char *) malloc((len1 + len2 + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	ft_memmove(dest, s1, len1);
	ft_memmove(dest + len1, s2, len2);
	dest[len1 + len2] = '\0';
	return (dest);
}
