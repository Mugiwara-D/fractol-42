/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maderuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 14:29:11 by maderuel          #+#    #+#             */
/*   Updated: 2023/05/19 15:45:11 by maderuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fract_ol.h>

void	my_pixel_put(t_img *f, int x, int y, int color)
{
	char	*dst;

	dst = f->ptr + (y * f->lil + x * (f->bpp / 8));
	*(unsigned int *) dst = color;
}

void	draw(t_img *frame, t_pxl *p, t_fractal *f,
		int (*t_comp)(t_pxl *, t_fractal *), int (*t_colors)(int i, int cop, t_fractal *))
{
	int	o;

	p->y = 0;
	o = 0;
	while (p->y < HF)
	{
		p->x = 0;
		while (p->x < LF)
		{
			o = t_comp(p, f);
			p->color = (t_colors(o, f->cop, f) * !(o == f->imax));
			my_pixel_put(frame, p->x, p->y, p->color);
			p->x++;
		}
		p->y++;
	}
}
