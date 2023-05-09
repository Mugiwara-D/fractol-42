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
	
	f->zoom.zx = ((float)x / LF) * (nw -w );
	f->zoom.zy = ((float)y / HF) * (nh - h);
	f->zoom.mz *= 1.1;
}
