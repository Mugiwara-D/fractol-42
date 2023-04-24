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
	float	zr;
	float	zi;
	int		i;
	float	cy;
	float	cx;
	float	tmp;

	cx = p->x / (LF / (0.6 - (-2.1))) + -2.1;
	cy = p->y / (HF / (1.2 - (-1.2))) + -1.2;
	i = 0;
	zr = 0;
	zi = 0;
	while ((zr * zr + zi * zi) < 4 && i < 50)
	{
		tmp = zr;
		zr = zr * zr - zi * zi + cx;
		zi = 2 * zi * tmp + cy;
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
