/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjose <vjose@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 15:51:26 by vjose             #+#    #+#             */
/*   Updated: 2021/10/11 16:37:20 by vjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	buf;

	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
		buf = (n % 10) + '0';
		write(fd, &buf, 1);
	}
	else if (n >= 0 && n < 10)
	{
		buf = n + '0';
		write(fd, &buf, 1);
	}
	else
	{
		write(fd, "-", 1);
		ft_putnbr_fd(-n, fd);
	}
}
