#include <fract_ol.h>

void	init_julia(t_fractal *f)
{
	f->base.ymax = ((1.5 - (-1.5)) * HF / LF / 2);
	f->base.ymin = -((1.5 - (-1.5)) * HF / LF / 2);

	f->base.xmax = ((1.2 - (-1.2)) * LF / HF / 2);
	f->base.xmin = -((1.2 - (-1.2)) * LF / HF / 2);
	f->imax = 250;
	f->zoom.mz = 1;
}

int	julia(t_pxl *p, t_fractal *f)
{
	float		tmp;
	int			i;

	f->c.r = -0.4;
	f->c.i = 0.6;
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
