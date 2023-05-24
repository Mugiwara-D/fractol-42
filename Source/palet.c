/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   palet.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maderuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 14:16:43 by maderuel          #+#    #+#             */
/*   Updated: 2023/05/24 14:17:10 by maderuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <fract_ol.h>

int	def(int i)
{
	if (i % 6 == 1)
		return (0x00009FF);
	else if (i % 6 == 2)
		return (0x00007CC);
	else if (i % 6 == 3)
		return (0x000005aa);
	else if (i % 6 == 4)
		return (0x00000377);
	else
		return (0x00000155);
}

int	linear(int i)
{
	if (i % 5 == 1)
		return (0x00559597);
	else if (i % 5 == 2)
		return (0x00d0e1b8);
	else if (i % 5 == 3)
		return (0x009c9b86);
	else if (i % 5 == 4)
		return (0x0087c9ac);
	else
		return (0x0044444c);
}

int	flame(int i)
{
	if (i % 5 == 1)
		return (0x00ffe000);
	else if (i % 5 == 2)
		return (0x00fbb405);
	else if (i % 5 == 3)
		return (0x00fb9a05);
	else if (i % 5 == 4)
		return (0x00fb6d05);
	else
		return (0x00fb4805);
}
