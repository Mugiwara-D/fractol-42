/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maderuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 14:20:28 by maderuel          #+#    #+#             */
/*   Updated: 2023/02/07 11:53:57 by maderuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../Include/libft.h"
#include "../../Include/ft_printf.h"

int	ft_putnchar(char c, int n)
{
	int	i;

	i = 0;
	if (n < 0)
		return (0);
	while (i++ < n)
		write(1, &c, 1);
	return (n);
}

int	ft_putmod_c(t_format *mod, va_list args)
{
	char	c;

	c = va_arg(args, int);
	if (mod->minus && mod->width > 1)
		return (ft_putchar_fd(c, 1) + ft_putnchar(' ', mod->width - 1));
	else if (!mod->minus && mod->width > 1)
		return (ft_putnchar(' ', mod->width - 1) + ft_putchar_fd(c, 1));
	else
		return (ft_putchar_fd(c, 1));
	return (0);
}
