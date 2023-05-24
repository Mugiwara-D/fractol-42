/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_number_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maderuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 11:48:15 by maderuel          #+#    #+#             */
/*   Updated: 2023/02/21 13:54:50 by maderuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../Include/libft.h"
#include "../../Include/ft_printf.h"

static int	numlen(int nbr)
{
	unsigned int	i;
	unsigned int	n;

	i = 1;
	if (nbr < 0 || nbr == -2147483648)
		n = (unsigned int) nbr * -1;
	else
		n = (unsigned int) nbr;
	while (n > 9)
	{
		n = n / 10;
		i++;
	}
	return (i + (nbr < 0));
}

int	nbr_preci(int nbr, t_format *mod)
{
	int	nl;
	int	l;

	nl = numlen(nbr) - (nbr < 0);
	l = ((mod->preci - nl) * (mod->preci >= nl));
	if (mod->dot && mod->preci && (mod->minus || mod->width || nbr < 0))
	{
		if (nbr < 0)
			return (ft_putchar_fd('-', 1)
				+ ft_putnchar('0', l) + ft_putunsigned_fd((nbr * -1), 1));
		else
			return (ft_putnchar('0', l) + ft_putnbr_fd(nbr, 1));
	}
	else if (mod->minus && mod->dot && mod->preci)
		return (ft_putnbr_fd(nbr, 1) + ft_putnchar('0', l + (nbr < 0)));
	else if (mod->preci)
		return (ft_putnchar('0', l) + ft_putnbr_fd(nbr, 1));
	return (0);
}

int	nbr_width(int nbr, t_format(*mod))
{
	int	l;

	l = numlen(nbr);
	l = mod->width - l * (mod->width > l);
	if (mod->zero && !mod->minus)
	{
		if (nbr >= 0)
			return (ft_putnchar('0', l) + ft_putnbr_fd(nbr, 1));
		else if (nbr == -2147483648)
			return (ft_putchar_fd('-', 1)
				+ ft_putnchar('0', l) + ft_putunsigned_fd(nbr * -1, 1));
		return (ft_putchar_fd('-', 1)
			+ ft_putnchar('0', l) + ft_putunsigned_fd(nbr * -1, 1));
	}
	else if (mod->minus && mod->zero)
		return (ft_putnbr_fd(nbr, 1) + ft_putnchar('0', l));
	else if (mod->minus)
		return (ft_putnbr_fd(nbr, 1) + ft_putnchar(' ', l));
	return (ft_putnchar(' ', l) + ft_putnbr_fd(nbr, 1));
}

int	nbr_mix(int nbr, t_format(*mod))
{
	int	nl;
	int	b;

	nl = numlen(nbr);
	if (mod->preci > nl)
		b = mod->preci;
	else
		b = nl;
	nl = mod->width - b - (nbr < 0 && mod->preci >= nl);
	if (mod->zero && mod->dot && mod->width && mod->preci)
		return (ft_putnchar(' ', nl) + nbr_preci(nbr, mod));
	else if (mod->minus && mod->dot && mod->width && mod->preci)
		return (nbr_preci(nbr, mod) + ft_putnchar(' ', nl));
	else if (mod->dot && mod->minus && mod->preci && !mod->width)
		return (nbr_preci(nbr, mod));
	else if ((mod->minus || mod->zero) && nl > 0 && mod->dot && !mod->preci)
		return (ft_putnchar(' ', mod->width));
	else if (nl < 0 && (mod->width || mod->preci))
		return (ft_putnbr_fd(nbr, 1));
	else if (mod->zero && mod->width && !mod->preci && mod->dot)
		return (ft_putnchar(' ', mod->width));
	return (0);
}

int	ft_print_nbr_mod(va_list args, t_format *mod)
{
	int	n;
	int	nbr;

	nbr = va_arg(args, int);
	n = numlen(nbr);
	if (mod->width > n && mod->preci <= n && !mod->dot)
		return (nbr_width(nbr, mod));
	else if (mod->preci >= n && !mod->width && !mod->minus)
		return (nbr_preci(nbr, mod));
	else if ((mod->minus || (mod->width > n)) && ((mod->preci > n) || mod->dot))
		return (nbr_mix(nbr, mod));
	else if (mod->zero && mod->dot && mod->width <= n && mod->preci)
		return (nbr_preci(nbr, mod));
	else if (mod->dot && mod->zero && !mod->preci && nbr == 0
		&& mod->width == n)
		return (ft_putnchar(' ', mod->width));
	else if (mod->plus && !mod->minus && !mod->preci && !mod->width && nbr >= 0)
		return (ft_putchar_fd('+', 1) + ft_putnbr_fd(nbr, 1));
	else if (mod->space && nbr >= 0)
		return (ft_putchar_fd(' ', 1) + ft_putnbr_fd(nbr, 1));
	else if (mod->dot && !mod->width && !mod->preci && nbr == 0)
		return (0);
	return (ft_putnbr_fd(nbr, 1));
}
