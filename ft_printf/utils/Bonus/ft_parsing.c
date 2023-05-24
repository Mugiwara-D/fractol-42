/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maderuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 10:15:12 by maderuel          #+#    #+#             */
/*   Updated: 2023/02/07 12:20:21 by maderuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../Include/ft_printf.h"
#include "../../Include/libft.h"

int	parse_nbr(int l, const char *s, t_format *mod)
{
	if ((s[l - 1] == '%' || s[l - 1] == '-' || s[l - 1] == '0') && !mod->width)
	{
		mod->width = ft_atoi(s + l);
		while (ft_isdigit(s[l]))
			l++;
	}
	else if (s[l - 1] == '.' || s[l - 1] == '0')
	{
		mod->preci = ft_atoi(s + l);
		while (ft_isdigit(s[l]))
			l++;
	}
	return (l);
}

int	ft_parse_flag(va_list args, const char *s, t_format *mod)
{
	int	l;

	l = 1;
	while ((ft_is_mod(s[l]) || ft_is_flag(s[l])) && s[l] != '\0')
	{
		if ((s[l] >= '1' && s[l] <= '9'))
			l = parse_nbr(l, s, mod);
		else if (ft_is_mod(s[l]))
			ft_set_mod(s[l++], mod);
		else if (ft_is_flag(s[l]))
		{
			ft_set_mod(s[l], mod);
			mod->len += ft_print_var_mod(mod, args);
			return (l);
		}
	}
	mod->len += ft_print_var_mod(mod, args);
	return (l);
}
