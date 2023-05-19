/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zierp.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maderuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 17:21:23 by maderuel          #+#    #+#             */
/*   Updated: 2023/05/19 18:22:39 by maderuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <fract_ol.h>

void	init_zierp(t_fractal *f)
{
	f->base.xmin = LF / HF / 2;
	f->base.xmax = (9 * LF / HF / 2);
	f->base.ymin = HF / LF / 2;
	f->base.ymax = (9 * HF / LF / 2);
	f->imax = 100;
}

int	zierpinski(t_pxl *p, t_fractal *f)
{
	int	i;

	i = 0;
	f->z = screen_to_complex(p, f);
	while (i < f->imax)
	{
		if ((int)f->z.r % 3 == 1 && (int)f->z.i % 3 == 1)
			return (i);
		f->z.r *= 3;
		f->z.i *= 3;
		i++;
	}
	return (i);
}
