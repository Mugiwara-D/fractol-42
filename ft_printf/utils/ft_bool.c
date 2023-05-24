/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bool.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maderuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 14:30:05 by maderuel          #+#    #+#             */
/*   Updated: 2023/01/03 18:15:55 by maderuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../Include/ft_printf.h"

int	ft_is_flag(const char c)
{
	return ((c == 'd') + (c == 's') + (c == 'x') + (c == 'X') + (c == 'i')
		+ (c == 'p') + (c == 'u') + (c == 'c') + (c == '%'));
}

int	ft_is_mod(const char c)
{
	return ((c == 35) + (c == 46) + (c == 32) + (c == 48) + (c == 43)
		+ (c == 45) + (c > '0' && c <= '9'));
}

int	ft_seen(t_format *mod, const char c)
{
	return (((mod->hash) * (c == 35)) + ((mod->dot) * (c == 46))
		+ ((mod->space) * (c == 32)) + ((mod->zero) * (c == 48))
		+ ((mod->plus) * (c == 43)) + ((mod->minus) * (c == 45)));
}
