/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesssanc <jesssanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 13:53:00 by jesssanc          #+#    #+#             */
/*   Updated: 2024/12/04 18:01:48 by jesssanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t		str_len1;
	size_t		str_len2;
	char		*str;
	size_t		i;
	size_t		j;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	j = 0;
	str_len1 = ft_strlen(s1);
	str_len2 = ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * ((str_len1 + str_len2) + 1));
	if (str == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	while (j < str_len2)
		str[i++] = s2[j++];
	str[i] = '\0';
	return (str);
}
