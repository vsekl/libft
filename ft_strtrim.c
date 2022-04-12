/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjose <vjose@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 15:52:23 by vjose             #+#    #+#             */
/*   Updated: 2021/10/13 18:00:49 by vjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check_c(char const c, char const *set)
{
	while (*set != '\0')
	{
		if (*set == c)
		{
			return (1);
		}
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	start;
	size_t	end;

	if (set == NULL || s1 == NULL)
		return (NULL);
	start = 0;
	end = ft_strlen(s1);
	if (*s1 == '\0')
		return (ft_strdup("\0"));
	while (s1[start] != '\0' && ft_check_c(s1[start], set) == 1)
		start++;
	end = end - 1;
	while (end > start && ft_check_c(s1[end], set) == 1)
		end--;
	str = ft_substr(s1, start, end - start + 1);
	return (str);
}
