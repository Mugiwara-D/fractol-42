/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned_mod.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maderuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 15:59:47 by maderuel          #+#    #+#             */
/*   Updated: 2023/02/21 13:48:44 by maderuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../Include/libft.h"
#include "../../Include/ft_printf.h"

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

static int	u_width(unsigned int n, t_format *mod)
{
	int	l;
	int	wl;

	l = numlen(n);
	wl = mod->width - l;
	if (wl > 0 && mod->minus)
		return (ft_putunsigned_fd(n, 1) + ft_putnchar(' ', wl));
	else if (wl > 0 && !mod->minus && mod->zero)
		return (ft_putnchar('0', wl) + ft_putunsigned_fd(n, 1));
	else if (wl > 0 && !mod->minus && !mod->zero)
		return (ft_putnchar(' ', wl) + ft_putunsigned_fd(n, 1));
	else if (wl <= 0)
		return (ft_putunsigned_fd(n, 1));
	return (0);
}

static int	u_preci(unsigned int n, t_format *mod)
{
	int	l;
	int	pl;

	l = numlen(n);
	pl = mod->preci - l;
	if (pl > 0)
		return (ft_putnchar('0', pl) + ft_putunsigned_fd(n, 1));
	else if (pl <= 0 && mod->preci != 0)
		return (ft_putunsigned_fd(n, 1));
	else if (mod->preci == 0 && n)
		return (ft_putunsigned_fd(n, 1));
	return (0);
}

static int	u_mix(unsigned int n, t_format *mod)
{
	int	l;
	int	nl;

	nl = numlen(n);
	l = mod->width - (mod->preci * (mod->preci > nl))
		- (nl * (nl >= mod->preci));
	if (mod->minus && mod->dot && !mod->zero)
		return (u_preci(n, mod) + ft_putnchar(' ', l + (!mod->preci && !n)));
	else if (mod->zero && mod->width && mod->preci && mod->dot)
		return (ft_putnchar(' ', l) + u_preci(n, mod));
	else if (mod->zero && mod->dot && !mod->preci && !n)
		return (ft_putnchar(' ', mod->width));
	return (ft_putunsigned_fd(n, 1));
}

int	ft_putunsigned_mod(va_list args, t_format *mod)
{
	unsigned int	nbr;

	nbr = va_arg(args, unsigned int);
	if (mod->width && !mod->preci && !mod->dot)
		return (u_width(nbr, mod));
	else if ((mod->preci || mod->dot) && !mod->width)
		return (u_preci(nbr, mod));
	else if ((mod->minus || mod->width || mod->zero)
		&& (mod->preci || mod->dot))
		return (u_mix(nbr, mod));
	return (ft_putunsigned_fd(nbr, 1));
}
