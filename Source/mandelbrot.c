/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maderuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 13:46:16 by maderuel          #+#    #+#             */
/*   Updated: 2023/04/28 15:21:53 by maderuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <fract_ol.h>

void	init_mandelbrot(t_fractal *f)
{
	
	f->base.ymax = 1.2;
	f->base.xmax = 0.6;
	f->base.ymin = -1.2;
	f->base.xmin = -2.1;
	f->imax = 100;
	f->zoom.mz = 300;
}

int	mandelbrot(t_pxl *p, t_fractal	*f)
{
	float		tmp;
	int		i;

	f->c.r = p->x / f->zoom.mz + f->base.xmin;
	f->c.i = p->y / f->zoom.mz + f->base.ymin;

	f->z.r = 0;
	f->z.i = 0;
	i = 0;

	while ((f->z.r * f->z.r + f->z.i * f->z.i) < 4 && i < f->imax)
	{
		tmp = f->z.r;
		f->z.r = f->z.r * f->z.r - f->z.i * f->z.i + f->c.r;
		f->z.i = 2 * f->z.i * tmp + f->c.i;
		i++;
	}
	return (i);
}
