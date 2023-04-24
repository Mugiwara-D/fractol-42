#include <fract_ol.h>

s_img	*init_img(s_mlx *mlx)
{
	s_img	*img;

	img = malloc(sizeof(s_img));
	img->img = mlx_new_image(mlx->ptr, LF, HF);
	img->ptr = mlx_get_data_addr(img->img, &img->bpp, &img->lil, &img->end);
	return (img);
}

void	my_pixel_put(s_img *f, int x, int y, int color)
{
	char	*dst;

	dst = f->ptr + (y * f->lil + x * (f->bpp / 8));
       *(unsigned int*)dst = color;	
}

int	div(void)
{

}

void	draw(s_img *frame, s_pxl *p)
{
	int	h;
	int	l;

	h = 0;
	p = 0x00000000;
	while (h < HF)
	{
		l = 0;
		while (l < LF)
		{
			if (div)
				p = 0x00000042;
			my_pixel_put(frame, l, h, p->color);
			l++;
		}
		h++;
	}
}
