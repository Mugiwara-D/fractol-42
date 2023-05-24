/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maderuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 16:01:52 by maderuel          #+#    #+#             */
/*   Updated: 2023/01/20 10:21:49 by maderuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../Include/ft_printf.h"
#include "../Include/libft.h"

static int	ft_sub_pv(t_format *mod, va_list args)
{
	char				*s;
	unsigned long long	p;

	if (mod->flag == 'd' || mod->flag == 'i')
		return (ft_putnbr_fd(va_arg(args, int), 1));
	else if (mod->flag == 's')
	{
		s = va_arg(args, char *);
		if (!s)
			return (write(1, "(null)", 6));
		else
			return (ft_putstr_fd(s, 1));
	}
	else if (mod->flag == 'p')
	{
		p = va_arg(args, unsigned long long);
		if (!p)
			return (write(1, "(nil)", 5));
		ft_putstr_fd("0x", 1);
		return (ft_puthex_fd(p, 1) + 2);
	}
	return (0);
}

int	ft_print_var(t_format *mod, va_list args)
{
	if (mod->flag == 'd' || mod->flag == 'i')
		return (ft_sub_pv(mod, args));
	else if (mod->flag == 's')
		return (ft_sub_pv(mod, args));
	else if (mod->flag == 'c')
		return (ft_putchar_fd(va_arg(args, int), 1));
	else if (mod->flag == 'x')
		return (ft_puthex_fd(va_arg(args, unsigned int), 1));
	else if (mod->flag == 'X')
		return (ft_puthex_maj_fd(va_arg(args, unsigned int), 1));
	else if (mod->flag == 'p')
		return (ft_sub_pv(mod, args));
	else if (mod->flag == '%')
		return (ft_putchar_fd('%', 1));
	else if (mod->flag == 'u')
		return (ft_putunsigned_fd(va_arg(args, unsigned int), 1));
	else
		return (0);
}
