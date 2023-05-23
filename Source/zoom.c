/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maderuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 14:23:45 by maderuel          #+#    #+#             */
/*   Updated: 2023/05/16 16:39:31 by maderuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fract_ol.h>

void	zoom_in(t_fractal *f, int x, int y)
{
	double	w;
	double	h;
	double	nx;
	double	ny;

	w = (f->base.xmax - f->base.xmin) * f->zoom.mz;
	h = (f->base.ymax - f->base.ymin) * f->zoom.mz;
	nx = (f->base.xmax - f->base.xmin) * (f->zoom.mz * 0.8);
	ny = (f->base.ymax - f->base.ymin) * (f->zoom.mz * 0.8);
	f->zoom.mz *= 0.8;
	f->zoom.zx -= ((double)x / LF) * (nx - w);
	f->zoom.zy -= ((double)y / HF) * (ny - h);
}

void	zoom_out(t_fractal *f, int x, int y)
{
	double	w;
	double	h;
	double	nx;
	double	ny;

	w = (f->base.xmax - f->base.xmin) * f->zoom.mz;
	h = (f->base.ymax - f->base.ymin) * f->zoom.mz;
	nx = (f->base.xmax - f->base.xmin) * (f->zoom.mz * 1.2);
	ny = (f->base.ymax - f->base.ymin) * (f->zoom.mz * 1.2);
	f->zoom.mz *= 1.2;
	f->zoom.zx -= ((double)x / LF) * (nx - w);
	f->zoom.zy -= ((double)y / HF) * (ny - h);
}

t_complex	screen_to_complex(t_pxl *p, t_fractal *f)
{
	t_complex	c;

	c.r = ((double)p->x / LF) * (f->base.xmax - f->base.xmin)
		* f->zoom.mz + f->base.xmin + f->zoom.zx;
	c.i = ((double)p->y / HF) * (f->base.ymax - f->base.ymin)
		* f->zoom.mz + f->base.ymin + f->zoom.zy;
	return (c);
}
