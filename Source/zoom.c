/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maderuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 14:23:45 by maderuel          #+#    #+#             */
/*   Updated: 2023/05/09 15:39:18 by maderuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fract_ol.h>

void	zoom_in(t_fractal *f, int x, int y)
{
	float	w;
	float	h;
	float 	nw;
	float	nh;

	w = (f->base.xmax - f->base.xmin) * (f->zoom.mz);
	h = (f->base.ymax - f->base.ymin) * (f->zoom.mz);
	nw = (f->base.xmax - f->base.xmin) * (f->zoom.mz * 1.1);
	nh = (f->base.ymax - f->base.ymin) * (f->zoom.mz * 1.1);
	f->zoom.zx = ((float)x / LF) * (nw - w);
	f->zoom.zy = ((float)y / HF) * (nh - h);
	f->zoom.mz *= 1.1;
}

t_complex	screen_to_complex(int x, int y, t_fractal *f)
{
	t_complex	p;

	p.r = (((float)x / LF) * (f->base.xmax - f->base.xmin)) * f->zoom.mz + f->base.xmin + f->zoom.zx;
	p.i = (((float)y / HF) * (f->base.ymax - f->base.ymin)) * f->zoom.mz + f->base.ymin + f->zoom.zy;
	return (p);
}
