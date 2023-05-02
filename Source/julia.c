#include <fract_ol.h>

void	init_julia(t_fractal *f)
{
	f->base.ymax = 1.2;
	f->base.xmax = 1;
	f->base.ymin = -1.2;
	f->base.xmin = -1;
	f->imax = 150;
	f->zoom.mz = 500;
}

int	julia(t_pxl *p, t_fractal *f)
{
	float		tmp;
	int			i;

	f->c.r = 0.3;
	f->c.i = 0.02;

	f->z.r = p->x / f->zoom.mz + f->base.xmin;
	f->z.i = p->y / f->zoom.mz + f->base.ymin;
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
