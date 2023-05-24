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

int	smooth(int i, t_fractal *f, int (*t_set_rgb)(double n))
{
	double	n;

	n = log(log(2) / log(f->z.r * f->z.r + f->z.i * f->z.i)) / log(2);
	n = i + 1 - n;
	return (t_set_rgb(n / f->imax));
}

int	get_colors(int i, int c, t_fractal *f)
{
	if (c == 0)
		return (smooth(i, f, &gris));
	else if (c == 1)
		return (smooth(i, f, &red));
	else if (c == 2)
		return (smooth(i, f, &green));
	else if (c == 3)
		return (smooth(i, f, &blue));
	else if (c == 4)
		return (smooth(i, f, &lsd));
	return (0);
}

void	update_colors(t_ref *ref)
{
	if (ref->f->cop == 4)
		ref->f->cop = 0;
	else
		ref->f->cop++;
	ref->m->img = del_img(ref);
	ft_bzero(&ref->m->img, sizeof(t_img));
	init_img(ref->m);
	render_img(ref->f, ref->p, ref->m);
}
