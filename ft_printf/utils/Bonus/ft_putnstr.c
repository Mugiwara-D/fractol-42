/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maderuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 12:29:59 by maderuel          #+#    #+#             */
/*   Updated: 2023/01/03 16:20:10 by maderuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../Include/libft.h"

int	ft_putnstr(char *str, unsigned int n)
{
	unsigned int	x;

	x = ft_strlen(str);
	if (!n || n > x)
		n = x;
	return (write(1, str, n));
}
