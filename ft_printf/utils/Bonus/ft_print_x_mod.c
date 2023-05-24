/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x_mod.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maderuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 14:01:38 by maderuel          #+#    #+#             */
/*   Updated: 2023/02/22 13:06:17 by maderuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../Include/ft_printf.h"
#include "../../Include/libft.h"

static int	xlen(unsigned long long nbr)
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

int	ft_putnhex(unsigned long long nbr, t_format *mod)
{
	int	nl;

	nl = xlen(nbr);
	if (mod->preci <= nl)
		mod->preci = nl;
	if (nbr == 0)
		return (ft_putchar_fd('0', 1));
	if (mod->flag == 'X')
		return (ft_puthex_maj_fd(nbr, 1));
	else if (mod->flag == 'x')
		return (ft_puthex_fd(nbr, 1));
	return (0);
}
