/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maderuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 11:55:38 by maderuel          #+#    #+#             */
/*   Updated: 2023/05/22 13:55:13 by maderuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fract_ol.h>

void	init_bns(t_fractal *f)
{
	f->base.ymax = ((2.2 - (-2.2)) * HF / LF / 2);
	f->base.ymin = -((2.2 - (-2.2)) * HF / LF / 2);
	f->base.xmax = ((2.2 - (-2.2)) * LF / HF / 2);
	f->base.xmin = -((2.2 - (-2.2)) * LF / HF / 2);
	f->imax = 1000;
	f->zoom.mz = 1;
	f->cop = 1;
}

int	burning_ship(t_pxl *p, t_fractal *f)
{
	int			i;
	t_complex	tmp;

	i = 0;
	f->z = screen_to_complex(p, f);
	f->c = screen_to_complex(p, f);
	while ((f->z.r * f->z.r) + (f->z.i * f->z.i) < 4 && i < f->imax)
	{
		f->z.r = dabs(f->z.r);
		f->z.i = dabs(f->z.i);
		tmp.r = f->z.r * f->z.r - f->z.i * f->z.i + f->c.r;
		tmp.i = f->z.r * f->z.i * 2 + f->c.i;
		f->z.r = tmp.r;
		f->z.i = tmp.i;
		i++;
	}
	return (i);
}
