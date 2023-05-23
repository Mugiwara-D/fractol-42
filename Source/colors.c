/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maderuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 15:18:22 by maderuel          #+#    #+#             */
/*   Updated: 2023/05/22 14:02:50 by maderuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <fract_ol.h>
#include <math.h>

int	def(int i)
{
	if (i % 6 == 1)
		return (0x00009FF);
	else if (i % 6 == 2)
		return (0x00007CC);
	else if (i % 6 == 3)
		return (0x000005aa);
	else if (i % 6 == 4)
		return (0x00000377);
	else
		return (0x00000155);
}

int	linear(int i)
{
	if (i % 5 == 1)
		return (0x00559597);
	else if (i % 5 == 2)
		return (0x00d0e1b8);
	else if (i % 5 == 3)
		return (0x009c9b86);
	else if (i % 5 == 4)
		return (0x0087c9ac);
	else
		return (0x0044444c);
}

int	flame(int i)
{
	if (i % 5 == 1)
		return (0x00ffe000);
	else if (i % 5 == 2)
		return (0x00fbb405);
	else if (i % 5 == 3)
		return (0x00fb9a05);
	else if (i % 5 == 4)
		return (0x00fb6d05);
	else
		return (0x00fb4805);
}

int	encode_color(unsigned char r, unsigned char g, unsigned char b)
{
	return (((r & 0xff) << 11) | ((g & 0xff) << 5) | (b & 0xff));
}

int	set_rgb(double n)
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	
	r = (unsigned char)(255 * n);
	g = 0;
	b = (unsigned char)(255 * (1 - n));
	return (encode_color(r, g, b));

}

int	smooth(int i, t_fractal *f)
{
	double n;

	n = log(log(2.0) / log(f->z.r * f->z.r + f->z.i * f->z.i)) / log(2);
	n = i + 1 - n;
	return (set_rgb(n / f->imax));
}

int	get_colors(int i, int c, t_fractal *f)
{
	if (c == 0)
		return (def(i));
	else if (c == 1)
		return (linear(i));
	else if (c == 2)
		return (flame(i));
	else if (c == 3)
		return (smooth(i, f));
	return (0);
}

void	update_colors(t_ref *ref)
{
	if (ref->f->cop == 3)
		ref->f->cop = 0;
	else
		ref->f->cop++;
	ref->m->img = del_img(ref);
	ft_bzero(&ref->m->img, sizeof(t_img));
	init_img(ref->m);
	render_img(ref->f, ref->p, ref->m);
}
