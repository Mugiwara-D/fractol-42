/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maderuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 16:47:19 by maderuel          #+#    #+#             */
/*   Updated: 2022/12/02 15:22:07 by maderuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
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
}
