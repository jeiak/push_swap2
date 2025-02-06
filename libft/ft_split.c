/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesssanc <jesssanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 13:35:49 by jesssanc          #+#    #+#             */
/*   Updated: 2024/12/09 12:44:04 by jesssanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	num_substrs(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			i++;
			while (*s && *s != c)
				s++;
		}
	}
	return (i);
}

static char	*substring(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (ft_substr(s, 0, len));
}

static void	free_result(char **result, size_t i)
{
	while (i--)
		free(result[i]);
	free(result);
}

static char	**res_split(char const *s, char c, char **substrs)
{
	size_t	i;

	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			substrs[i] = substring(s, c);
			if (!substrs[i])
			{
				free_result(substrs, i);
				return (NULL);
			}
			i++;
			while (*s && *s != c)
				s++;
		}
	}
	substrs[i] = NULL;
	return (substrs);
}

char	**ft_split(char const *s, char c)
{
	size_t	num_subs;
	char	**substrs;

	if (!s)
		return (NULL);
	num_subs = num_substrs(s, c);
	substrs = (char **)malloc(sizeof(char *) * (num_subs + 1));
	if (substrs == NULL)
		return (NULL);
	return (res_split(s, c, substrs));
}
