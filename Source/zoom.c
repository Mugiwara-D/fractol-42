/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maderuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 14:23:45 by maderuel          #+#    #+#             */
/*   Updated: 2023/05/11 15:01:53 by maderuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fract_ol.h>

void	zoom_in(t_fractal *f, int x, int y)
{
	float	w;
	float	h;
	float	nx;
	float	ny;

	w = (f->base.xmax - f->base.xmin) * f->zoom.mz;
	h = (f->base.ymax - f->base.ymin) * f->zoom.mz;
	nx = (f->base.xmax - f->base.xmin) * (f->zoom.mz * 0.9);
	ny = (f->base.ymax - f->base.ymin) * (f->zoom.mz * 0.9);
	f->zoom.mz *= 0.9;
	f->zoom.zx -= ((float)x / LF) * (nx - w);
	f->zoom.zy -= ((float)y / HF) * (ny - h);
}

void	zoom_out(t_fractal *f, int x, int y)
{
	float	w;
	float	h;
	float	nx;
	float	ny;

	w = (f->base.xmax - f->base.xmin) * f->zoom.mz;
	h = (f->base.ymax - f->base.ymin) * f->zoom.mz;
	nx = (f->base.xmax - f->base.xmin) * (f->zoom.mz * 1.1);
	ny = (f->base.ymax - f->base.ymin) * (f->zoom.mz * 1.1);
	f->zoom.mz *= 1.1;
	f->zoom.zx -= ((float)x / LF) * (nx - w);
	f->zoom.zy -= ((float)y / HF) * (ny - h);
}

t_complex	screen_to_complex(t_pxl *p, t_fractal *f)
{
	t_complex	c;

	c.r = ((float)p->x / LF) * (f->base.xmax - f->base.xmin) * f->zoom.mz + f->base.xmin + f->zoom.zx;
	c.i = ((float)p->y / HF) * (f->base.ymax - f->base.ymin) * f->zoom.mz + f->base.ymin + f->zoom.zy;
	return (c);
}
