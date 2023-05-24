/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printer_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maderuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 10:08:59 by maderuel          #+#    #+#             */
/*   Updated: 2023/02/21 13:51:22 by maderuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../Include/libft.h"
#include "../../Include/ft_printf.h"

int	ft_print_var_mod(t_format *mod, va_list args)
{
	if (mod->flag == 's')
		return (ft_print_str_mod(args, mod));
	else if (mod->flag == 'x' || mod->flag == 'X')
		return (ft_puthex_mod(args, mod));
	else if (mod->flag == 'd' || mod->flag == 'i')
		return (ft_print_nbr_mod(args, mod));
	else if (mod->flag == 'u')
		return (ft_putunsigned_mod(args, mod));
	else if (mod->flag == 'c')
		return (ft_putmod_c(mod, args));
	else if (mod->flag == 'p')
		return (print_mod_p(args, mod));
	return (0);
}
