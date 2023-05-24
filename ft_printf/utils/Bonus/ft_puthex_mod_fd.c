/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_mod_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maderuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 14:50:37 by maderuel          #+#    #+#             */
/*   Updated: 2023/02/21 15:34:19 by maderuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../Include/ft_printf.h"
#include "../../Include/libft.h"

static int	xlen(unsigned long long nbr)
{
	int	l;

	l = 0;
	if (!nbr)
		return (0);
	while (nbr > 0)
	{
		nbr /= 16;
		l++;
	}
	return (l);
}

static int	xpreci(unsigned long long nbr, t_format *mod)
{
	int	l;

	l = xlen(nbr);
	if (mod->preci == 0 && nbr == 0)
		return (0);
	else if (mod->preci >= l && nbr > 0)
		return (ft_putnchar('0', mod->preci - l) + ft_putnhex(nbr, mod));
	else if (mod->preci && nbr == 0)
		return (ft_putnchar('0', mod->preci));
	return (ft_putnhex(nbr, mod));
}

static int	xwidth(unsigned long long nbr, t_format *mod)
{
	int	l;
	int	wl;

	if (nbr)
		l = xlen(nbr);
	else
		l = 0;
	wl = mod->width - (l + (nbr == 0));
	if (!mod->minus && !mod->zero && mod->width)
		return (ft_putnchar(' ', wl) + ft_putnhex(nbr, mod));
	else if (mod->minus && wl)
		return (ft_putnhex(nbr, mod) + ft_putnchar(' ', wl));
	else if (mod->zero)
		return (ft_putnchar('0', wl) + ft_putnhex(nbr, mod));
	return (ft_putnhex(nbr, mod));
}

static int	xmix(unsigned long long nbr, t_format *mod)
{
	int	wl;
	int	l;

	l = xlen(nbr);
	wl = mod->width - (mod->preci * (mod->preci > l)) - (l * (mod->preci <= l));
	if (mod->minus && wl > 0)
		return (xpreci(nbr, mod) + ft_putnchar(' ', wl));
	else if (!mod->minus && wl > 0 && mod->preci)
		return (ft_putnchar(' ', wl) + xpreci(nbr, mod));
	else if (!mod->preci && mod->dot && (mod->minus || mod->zero)
		&& mod->width && nbr == 0)
		return (ft_putnchar(' ', mod->width));
	else if (wl <= 0)
		return (xpreci(nbr, mod));
	return (ft_putnhex(nbr, mod));
}

int	ft_puthex_mod(va_list args, t_format *mod)
{
	unsigned long long	exn;

	exn = va_arg(args, unsigned long long);
	if (mod->width && !mod->preci && !mod->dot)
		return (xwidth(exn, mod));
	else if (mod->dot && !mod->width)
		return (xpreci(exn, mod));
	else if ((mod->minus || mod->width) && (mod->dot || mod->preci))
		return (xmix(exn, mod));
	else if (mod->hash && exn > 0)
	{
		if (mod->flag == 'X')
			return (ft_putstr_fd("0X", 1) + ft_putnhex(exn, mod));
		return (ft_putstr_fd("0x", 1) + ft_putnhex(exn, mod));
	}
	return (ft_putnhex(exn, mod));
}
