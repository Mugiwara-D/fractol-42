/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maderuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 15:59:47 by maderuel          #+#    #+#             */
/*   Updated: 2023/01/18 14:09:08 by maderuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../Include/libft.h"
#include "../Include/ft_printf.h"

static int	numlen(unsigned int nbr)
{
	unsigned int	i;
	unsigned int	n;

	i = 1;
	n = nbr;
	while (n > 9)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

int	ft_putunsigned_fd(unsigned int nbr, int fd)
{
	unsigned int	i;

	i = nbr;
	if (i > 9)
	{
		ft_putnbr_fd((i / 10), fd);
		i = i % 10;
	}
	ft_putchar_fd((i + 48), fd);
	return (numlen(nbr));
}
