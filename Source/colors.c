/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maderuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 15:18:22 by maderuel          #+#    #+#             */
/*   Updated: 2023/05/24 14:33:00 by maderuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <fract_ol.h>
#include <math.h>

int	set_rgb(double n)
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;

	r = (unsigned char)(110 * n);
	g = (unsigned char)(200 * n);
	b = (unsigned char)(255 * n);
	return ((r << 16) | (g << 8) | b);
}

int	smooth(int i, t_fractal *f)
{
	double	n;

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
