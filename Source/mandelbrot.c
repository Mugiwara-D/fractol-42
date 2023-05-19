/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maderuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 13:46:16 by maderuel          #+#    #+#             */
/*   Updated: 2023/05/19 15:41:23 by maderuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <fract_ol.h>

t_fractal	*init_mandelbrot(t_fractal *f)
{
	f->base.ymax = ((2.1 - (-2.1)) * HF / LF / 2);
	f->base.ymin = -((2.1 - (-2.1)) * HF / LF / 2);
	f->base.xmax = ((1.2 - (-1.2)) * LF / HF / 2);
	f->base.xmin = -((1.2 - (-1.2)) * LF / HF / 2);
	f->imax = 100;
	f->zoom.mz = 1;
	f->cop = 1;
	return (f);
}

int	mandelbrot(t_pxl *p, t_fractal	*f)
{
	float	tmp;
	int		i;

	f->z.r = 0;
	f->z.i = 0;
	f->c = screen_to_complex(p, f);
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
