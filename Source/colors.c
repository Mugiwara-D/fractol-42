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

int	smooth(int i, t_fractal *f, int (*t_set_rgb)(int i, double n))
{
	double	n;
	double	m;
	double	r;

	n = log(f->z.r * f->z.r + f->z.i * f->z.i) / 2.0f ;
	m = log(n / log(2)) / log(2);
	r = i + 1 - m;
	return (t_set_rgb(i, (r / f->imax)));
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
/*branchless get*
 *
 * return ((smooth(i, f, &gris) * (c == 0)) + (smooth(i, f, &red) * (c == 1)) +
 * (smooth(i, f, &green) * (c == 2)) + (smooth(i, f, &blue) * (c == 3)) +
 * (smooth(i, f, &lsd) * (c == 4)));
*/

