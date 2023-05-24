/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maderuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 14:25:59 by maderuel          #+#    #+#             */
/*   Updated: 2023/05/24 14:36:04 by maderuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fract_ol.h>

void	init_julia(t_fractal *f, char *arg)
{
	f->base.ymax = ((1.5 - (-1.5)) * HF / LF / 2);
	f->base.ymin = -((1.5 - (-1.5)) * HF / LF / 2);
	f->base.xmax = ((1.2 - (-1.2)) * LF / HF / 2);
	f->base.xmin = -((1.2 - (-1.2)) * LF / HF / 2);
	f->imax = 100;
	f->zoom.mz = 1;
	if (!s_cmp(arg, "1"))
		f->c = (t_complex){.r = -0.8, .i = 0.156};
	else if (!s_cmp(arg, "2"))
		f->c = (t_complex){.r = -0.4, .i = 0.6};
	else
		f->c = (t_complex){.r = 0.0, .i = 0.8};
}

int	julia(t_pxl *p, t_fractal *f)
{
	double		tmp;
	int			i;

	f->z = screen_to_complex(p, f);
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
