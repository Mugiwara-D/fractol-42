/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maderuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 16:47:19 by maderuel          #+#    #+#             */
/*   Updated: 2023/02/21 14:23:38 by maderuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	numlen(int nbr)
{
	unsigned int	i;
	unsigned int	n;

	i = 1;
	if (nbr < 0)
		n = nbr * -1;
	else
		n = nbr;
	while (n > 9)
	{
		n = n / 10;
		i++;
	}
	return (i + (nbr < 0));
}

int	ft_putnbr_fd(int n, int fd)
{
	unsigned int	i;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		i = n * -1 ;
	}
	else
		i = n;
	if (i > 9)
	{
		ft_putnbr_fd((i / 10), fd);
		i = i % 10;
	}
	ft_putchar_fd((i + 48), fd);
	return (numlen(n));
}
