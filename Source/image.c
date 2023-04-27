/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maderuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 14:29:11 by maderuel          #+#    #+#             */
/*   Updated: 2023/04/24 16:52:31 by maderuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fract_ol.h>

t_img	*init_img(t_mlx *mlx)
{
	t_img	*img;

	img = malloc(sizeof(t_img));
	img->img = mlx_new_image(mlx->ptr, LF, HF);
	img->ptr = mlx_get_data_addr(img->img, &img->bpp, &img->lil, &img->end);
	return (img);
}

void	my_pixel_put(t_img *f, int x, int y, int color)
{
	char	*dst;

	dst = f->ptr + (y * f->lil + x * (f->bpp / 8));
    *(unsigned int*) dst = color;
}

int	mandelbrot(t_pxl *p)
{
	t_complex	z;
	t_complex	c;
	t_fractal	f;
	float		zoomx;
	float		zoomy;
	float		tmp;
	int		i;
	
	f.ymax = 1.2;
	f.xmax = 0.6;
	f.ymin = -1.2;
	f.xmin = -2.1;
	f.imax = 50;

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

void	draw(t_img *frame, t_pxl *p)
{
	int	h;
	int	l;
	int o;

	h = 0;
	p->color = 0x00FFFFFF;
	p->x = 0;
	p->y = 0;
	while (h < HF)
	{
		l = 0;
		p->x = 0;
		while (l < LF)
		{
			o = mandelbrot(p);
			if (o == 50)
				p->color = 0x000000FF;
			else
				p->color = 0x00990000;
			my_pixel_put(frame, l, h, p->color);
			p->x++;
			l++;
		}
		p->y++;
		h++;
	}
}
