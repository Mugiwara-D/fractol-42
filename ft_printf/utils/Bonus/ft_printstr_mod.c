/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr_mod.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maderuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 15:49:56 by maderuel          #+#    #+#             */
/*   Updated: 2023/02/21 13:52:14 by maderuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../Include/libft.h"
#include "../../Include/ft_printf.h"

int	ft_putnull(t_format *mod)
{
	if (mod->width || mod->preci >= 6)
	{
		mod->width = (mod->width - 6) * (mod->width > 6);
		if (mod->width > 0)
			ft_putnchar(' ', mod->width);
		return (write(1, "(null)", 6) + mod->width);
	}
	else
		return (write(1, 0, 0));
}

int	str_width(char *s, t_format *mod)
{
	int	l;

	l = ft_strlen(s);
	mod->width = (mod->width - l) * (mod->width > l);
	if (!mod->minus && mod->width)
		return (ft_putnchar(' ', mod->width) + ft_putstr_fd(s, 1));
	else if (mod->width && mod->minus)
		return (ft_putstr_fd(s, 1) + ft_putnchar(' ', mod->width));
	else
		return (ft_putstr_fd(s, 1));
}

int	str_preci(char *s, t_format *mod)
{
	int	l;

	l = ft_strlen(s);
	mod->preci = mod->preci * (mod->preci < l);
	if (mod->preci)
		return (ft_putnstr(s, mod->preci));
	else
		return (ft_putstr_fd(s, 1));
}

int	str_mix(char *s, t_format *mod)
{
	int	sl;
	int	n;

	sl = ft_strlen(s);
	n = mod->width - (mod->preci * (mod->preci <= sl));
	n = n - (sl * (mod->preci > sl));
	if (mod->minus && mod->dot && (mod->width || mod->preci))
		return (str_preci(s, mod) + ft_putnchar(' ', n));
	else if (mod->width && mod->preci && mod->dot && !mod->minus)
		return (ft_putnchar(' ', n) + str_preci(s, mod));
	else if (mod->width && mod->dot && !mod->minus && !mod->preci)
		return (ft_putnchar(' ', mod->width));
	return (0);
}

int	ft_print_str_mod(va_list args, t_format *mod)
{
	char	*s;

	s = va_arg(args, char *);
	if (!s)
		return (ft_putnull(mod));
	else if ((mod->width || mod->minus) && (mod->preci || mod->dot))
		return (str_mix(s, mod));
	else if (mod->width && !mod->preci && !mod->dot)
		return (str_width(s, mod));
	else if (!mod->width && mod->preci && !mod->minus)
		return (str_preci(s, mod));
	else if (mod->dot && !mod->preci && !mod->width)
		return (0);
	return (ft_putstr_fd(s, 1));
}
