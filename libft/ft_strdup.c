/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesssanc <jesssanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 10:53:46 by jesssanc          #+#    #+#             */
/*   Updated: 2024/11/27 11:42:19 by jesssanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *src)
{
	size_t	len;
	char	*dest;

	len = 0;
	while (src[len] != '\0')
		len ++;
	dest = (char *)malloc(sizeof(char) * (len + 1));
	if (dest == NULL)
		return (NULL);
	len = 0;
	while (src[len] != '\0')
	{
		dest[len] = src[len];
		len ++;
	}
	dest[len] = '\0';
	return (dest);
}
