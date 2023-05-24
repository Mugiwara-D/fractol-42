/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maderuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 14:50:37 by maderuel          #+#    #+#             */
/*   Updated: 2023/01/18 14:28:05 by maderuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../Include/ft_printf.h"
#include "../Include/libft.h"

static int	ft_numlen(unsigned long long nbr)
{
	int	l;

	l = 0;
	while (nbr > 0)
	{
		nbr /= 16;
		l++;
	}
	return (l);
}

int	ft_puthex_fd(unsigned long long nbr, int fd)
{
	unsigned long long	n;
	char				*base;
	char				*num;
	int					i;

	if (nbr == 0)
		return (ft_putchar_fd('0', 1));
	i = ft_numlen(nbr);
	base = "0123456789abcdef";
	num = malloc(i + 1 * sizeof(char));
	if (!num)
		return (free(num), 0);
	n = nbr;
	num[i] = '\0';
	while (--i >= 0)
	{
		num[i] = base[n % 16];
		n = n / 16;
	}
	ft_putstr_fd(num, fd);
	free(num);
	return (ft_numlen(nbr));
}

int	ft_puthex_maj_fd(unsigned long long nbr, int fd)
{
	unsigned long long	n;
	char				*base;
	char				*num;
	int					i;

	if (nbr == 0)
		return (ft_putchar_fd('0', 1));
	i = ft_numlen(nbr);
	base = "0123456789ABCDEF";
	num = malloc(i + 1 * sizeof(char));
	if (!num)
		return (free(num), 0);
	n = nbr;
	num[i] = '\0';
	while (--i >= 0)
	{
		num[i] = base[n % 16];
		n = n / 16;
	}
	ft_putstr_fd(num, fd);
	free(num);
	return (ft_numlen(nbr));
}
