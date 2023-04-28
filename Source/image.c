/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maderuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 14:29:11 by maderuel          #+#    #+#             */
/*   Updated: 2023/04/28 15:19:02 by maderuel         ###   ########.fr       */
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
	*(unsigned int *) dst = color;
}

int	palet(int i)
{
	if (i > 75)
		return (0x00FF0000);
	else if (i > 50)
		return (0x00880000);
	else if (i > 25)
		return (0x00110000);
	else
		return (0x00000000);
}

void	draw(t_img *frame, t_pxl *p)
{
	int	h;
	int	l;
	int	o;

	h = 0;
	p->x = 0;
	p->y = 0;
	while (h < HF)
	{
		l = 0;
		p->x = 0;
		while (l < LF)
		{
			o = mandelbrot(p);
			if (o == 100)
				p->color = 0x00000000;
			else
				p->color = palet(o);
			my_pixel_put(frame, l, h, p->color);
			p->x++;
			l++;
		}
		p->y++;
		h++;
	}
}
