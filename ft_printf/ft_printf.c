/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maderuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 13:14:34 by maderuel          #+#    #+#             */
/*   Updated: 2023/01/18 12:16:12 by maderuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "./Include/ft_printf.h"
#include "./Include/libft.h"

static int	ft_check_flag(va_list args, const char *str, t_format *mod)
{
	int	i;

	i = 1;
	ft_init_mod(mod);
	if (ft_is_flag(str[i]) && str[i - 1] == 37)
	{
		ft_set_mod(str[i], mod);
		mod->len += ft_print_var(mod, args);
		return (i);
	}
	else if (!ft_is_flag(str[i]) && ft_is_mod(str[i]) && str[i - 1] == 37)
		return (ft_parse_flag(args, str, mod));
	else
		return (0);
	return (i);
}

int	ft_printf(const char *str_in, ...)
{
	unsigned int	i;
	va_list			args;
	t_format		*mod;

	va_start(args, str_in);
	mod = malloc(sizeof(t_format));
	if (!mod)
		return (0);
	i = 0;
	ft_init_mod(mod);
	mod->len = 0;
	while (str_in[i])
	{
		if (str_in[i] == 37)
			i = i + ft_check_flag(args, str_in + i, mod);
		else
			mod->len = mod->len + ft_putchar_fd(str_in[i], 1);
		i++;
	}	
	va_end(args);
	i = mod->len;
	free(mod);
	return (i);
}
