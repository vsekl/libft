/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjose <vjose@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 15:50:25 by vjose             #+#    #+#             */
/*   Updated: 2021/10/11 17:17:40 by vjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_size(int n)
{
	size_t	size;

	size = 1;
	while (n >= 10 || n <= -10)
	{
		size++;
		n = n / 10;
	}
	return (size);
}

static int	ft_pow(size_t size)
{
	int	i;

	i = 1;
	while (size > 0)
	{
		i = i * 10;
		size--;
	}
	return (i);
}

static char	*ft_create_str(int n, size_t size)
{
	char	*str;

	if (n < 0)
		str = malloc(sizeof(char) * (size + 2));
	else
		str = malloc(sizeof(char) * (size + 1));
	if (str == NULL)
		return (NULL);
	return (str);
}

static void	ft_fill_str(char *str, size_t size, size_t i, int n)
{
	while (i < size)
	{
		str[i] = n / ft_pow(size - (i + 1)) + '0';
		n = n - ft_pow(size - (i + 1)) * (str[i] - '0');
		i++;
	}
	str[i] = '\0';
}

char	*ft_itoa(int n)
{
	size_t	size;
	size_t	i;
	char	*str;
	char	*start;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	size = ft_size(n);
	str = ft_create_str(n, size);
	if (str == NULL)
		return (NULL);
	start = str;
	i = 0;
	if (n < 0)
	{
		str++[i] = '-';
		n = -n;
	}
	ft_fill_str(str, size, i, n);
	return (start);
}
