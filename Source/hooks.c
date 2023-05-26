/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maderuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 14:04:54 by maderuel          #+#    #+#             */
/*   Updated: 2023/05/25 15:02:37 by maderuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <fract_ol.h>

void	update_julia(t_ref *ref, int keycode)
{
	if (keycode == K_PLUS)
	{
		ref->m->img = del_img(ref);
		ref->f->c = (t_complex){.r = (ref->f->c.r + 0.1),
			.i = (ref->f->c.i + 0.1)};
		ft_bzero(&ref->m->img, sizeof(t_img));
		init_img(ref->m);
		render_img(ref->f, ref->p, ref->m);
	}
	else if (keycode == K_MINUS)
	{
		ref->m->img = del_img(ref);
		ref->f->c = (t_complex){.r = (ref->f->c.r - 0.1),
			.i = (ref->f->c.i - 0.1)};
		ft_bzero(&ref->m->img, sizeof(t_img));
		init_img(ref->m);
		render_img(ref->f, ref->p, ref->m);
	}
}

int	key_hook(int keycode, t_ref *ref)
{
	if (keycode == K_ESC)
		end_prog(ref);
	else if (keycode == K_C)
		update_colors(ref);
	else if (keycode == K_UP || keycode == K_DOWN
		|| keycode == K_LEFT || keycode == K_RIGHT)
		key_move(keycode, ref);
	else if ((keycode == K_PLUS || keycode == K_MINUS)
		&& !s_cmp(ref->f->name, "julia"))
		update_julia(ref, keycode);
	return (0);
}

void	julia_mos(int x, int y, t_ref *ref)
{
		ref->m->img = del_img(ref);
		ref->f->c = (t_complex){.r = (((double)x / LF) * (ref->f->base.xmax - ref->f->base.xmin)
				* ref->f->zoom.mz + ref->f->base.xmin + ref->f->zoom.zx),
			.i = (((double)y / HF) * (ref->f->base.ymax - ref->f->base.ymin)
				* ref->f->zoom.mz + ref->f->base.ymin + ref->f->zoom.zy)};
		ft_bzero(&ref->m->img, sizeof(t_img));
		init_img(ref->m);
		render_img(ref->f, ref->p, ref->m);
}

void	key_move(int key, t_ref *ref)
{
	double	w;
	double	h;

	w = (ref->f->base.xmax - ref->f->base.xmin) * ref->f->zoom.mz;
	h = (ref->f->base.ymax - ref->f->base.ymin) * ref->f->zoom.mz;
	if (key == K_UP)
		ref->f->zoom.zy += h * 0.05;
	if (key == K_DOWN)
		ref->f->zoom.zy -= h * 0.05;
	if (key == K_LEFT)
		ref->f->zoom.zx += w * 0.05;
	if (key == K_RIGHT)
		ref->f->zoom.zx -= w * 0.05;
	ref->m->img = del_img(ref);
	ft_bzero(&ref->m->img, sizeof(t_img));
	init_img(ref->m);
	render_img(ref->f, ref->p, ref->m);
}

int	mos_hook(int btn, int x, int y, t_ref *ref)
{	
	if (btn == 4)
	{
		ref->m->img = del_img(ref);
		zoom_in(ref->f, x, y);
		ft_bzero(&ref->m->img, sizeof(t_img));
		init_img(ref->m);
		render_img(ref->f, ref->p, ref->m);
	}
	else if (btn == 5)
	{
		ref->m->img = del_img(ref);
		zoom_out(ref->f, x, y);
		ft_bzero(&ref->m->img, sizeof(t_img));
		init_img(ref->m);
		render_img(ref->f, ref->p, ref->m);
	}
	else if (btn == 1 && !s_cmp(ref->f->name, "julia"))
			julia_mos(x, y, ref);
	return (0);
}
