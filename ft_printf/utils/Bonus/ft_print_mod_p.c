/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_mod_p.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maderuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 13:55:51 by maderuel          #+#    #+#             */
/*   Updated: 2023/02/21 13:56:39 by maderuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../Include/libft.h"
#include "../../Include/ft_printf.h"

static int	numlen(unsigned long long p)
{
	int					i;
	unsigned long long	n;

	n = p;
	i = 0;
	while (n > 1)
	{
		n /= 16;
		i++;
	}
	return (i);
}

static int	p_null(t_format *mod)
{
	if (mod->width <= 5)
		return (ft_putstr_fd("(nil)", 1));
	else if (mod->minus)
		return (ft_putstr_fd("(nil)", 1) + ft_putnchar(' ', mod->width - 5));
	else
		return (ft_putnchar(' ', mod->width - 5) + ft_putstr_fd("(nil)", 1));
}

int	print_mod_p(va_list args, t_format *mod)
{
	unsigned long long	p;

	p = va_arg(args, unsigned long long);
	if (!p)
		return (p_null(mod));
	mod->width -= numlen(p) + 2;
	if (mod->minus && mod->width)
		return (ft_putstr_fd("0x", 1) + ft_puthex_fd(p, 1)
			+ ft_putnchar(' ', mod->width));
	else if (mod->width)
		return (ft_putnchar(' ', mod->width) + ft_putstr_fd("0x", 1)
			+ ft_puthex_fd(p, 1));
	return (ft_putstr_fd("0x", 1) + ft_puthex_fd(p, 1));
}
