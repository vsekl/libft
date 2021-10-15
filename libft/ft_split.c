/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjose <vjose@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 15:51:35 by vjose             #+#    #+#             */
/*   Updated: 2021/10/15 18:50:43 by vjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_words(char const *s, char c)
{
	size_t	counter;
	int		flag;

	counter = 0;
	flag = 1;
	while (*s != 0)
	{
		if (*s == c)
			flag = 1;
		while (*s == c)
			s++;
		if (*s != 0 && flag == 1)
		{
			counter++;
			flag = 0;
		}
		while (*s != c && *s != 0)
			s++;
	}
	return (counter);
}

static size_t	ft_count_letters(char const *s, char c)
{
	size_t	counter;

	counter = 0;
	while (*s != 0)
	{
		if (*s != c)
			counter++;
		s++;
	}
	return (counter);
}

static void	ft_fill_tab(char **tab, char const *s, char c, size_t words_size)
{
	size_t	i;
	size_t	j;
	char	*ptr;
	size_t	counter;

	i = 0;
	j = 0;
	counter = 0;
	ptr = (char *)tab + sizeof(char *) * (words_size + 1);
	while (i < words_size)
	{
		while (*s == c && *s != 0)
			s++;
		tab[i] = ptr + counter;
		while (*s != c && *s != '\0')
		{
			tab[i][j++] = *s;
			counter++;
			s++;
		}
		tab[i++][j] = '\0';
		counter++;
		j = 0;
	}
	tab[i] = NULL;
}

char	**ft_split(char const *s, char c)
{
	size_t	words_size;
	size_t	letters_size;
	char	**tab;

	if (s == NULL)
		return (NULL);
	words_size = ft_count_words(s, c);
	letters_size = ft_count_letters(s, c);
	tab = malloc(sizeof(char *) * (words_size + 1) + \
	sizeof(char) * (letters_size + words_size));
	if (tab == NULL)
		return (NULL);
	ft_fill_tab(tab, s, c, words_size);
	return (tab);
}
