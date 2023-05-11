/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maderuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 14:29:11 by maderuel          #+#    #+#             */
/*   Updated: 2023/05/09 15:27:13 by maderuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fract_ol.h>

void	my_pixel_put(t_img *f, int x, int y, int color)
{
	char	*dst;

	dst = f->ptr + (y * f->lil + x * (f->bpp / 8));
	*(unsigned int *) dst = color;
}

int	palet(int i)
{
	if (i > 100)
		return (0x00003300);
	else if (i > 75)
		return (0x00FF0000);
	else if (i > 50)
		return (0x00880000);
	else if (i > 25)
		return (0x00700000);
	else
		return (0x00500000);
}



void	draw(t_img *frame, t_pxl *p, t_fractal *f, int	(*comp)(t_pxl *,t_fractal *))
{
	int	o;

	p->y = 0;
	while (p->y < HF)
	{
		p->x = 0;
		while (p->x < LF)
		{
			o = comp(p, f);
			if (o == f->imax)
				p->color = 0x00000000;
			else
				p->color = palet(o);
			my_pixel_put(frame, p->x, p->y, p->color);
			p->x++;
		}
		p->y++;
	}
}
