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

t_fractal	init_mandelbrot(void)
{
	t_fractal	f;
	
	f.ymax = 1;
	f.xmax = 0.4;
	f.ymin = -1;
	f.xmin = -1.9;
	f.imax = 100;
	return (f);
}

int	mandelbrot(t_pxl *p)
{
	t_complex	z;
	t_complex	c;
	t_fractal	f;
	float		zoomx;
	float		zoomy;
	float		tmp;
	int			i;

	f = init_mandelbrot();
	zoomx = LF / (f.xmax - f.xmin);
	zoomy = HF / (f.ymax - f.ymin);

	c.r = p->x / zoomx + f.xmin;
	c.i = p->y / zoomy + f.ymin;

	z.r = 0;
	z.i = 0;
	i = 0;

	while ((z.r * z.r + z.i * z.i) < 4 && i < f.imax)
	{
		tmp = z.r;
		z.r = z.r * z.r - z.i * z.i + c.r;
		z.i = 2 * z.i * tmp + c.i;
		i++;
	}
	return (i);
}
