/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maderuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 14:25:22 by maderuel          #+#    #+#             */
/*   Updated: 2022/12/15 14:34:04 by maderuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../Include/ft_printf.h"
#include "../Include/libft.h"

t_format	*ft_init_mod(t_format *mod)
{
	mod->preci = 0;
	mod->width = 0;
	mod->hash = 0;
	mod->dot = 0;
	mod->space = 0;
	mod->zero = 0;
	mod->plus = 0;
	mod->minus = 0;
	return (mod);
}

t_format	*ft_set_mod(char f, t_format *mod)
{
	mod->hash += (f == 35);
	mod->dot += (f == 46);
	mod->space += (f == 32);
	mod->zero += (f == 48);
	mod->plus += (f == 43);
	mod->minus += (f == 45);
	mod->flag = f;
	return (mod);
}
