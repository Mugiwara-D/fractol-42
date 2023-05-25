/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maderuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 14:04:54 by maderuel          #+#    #+#             */
/*   Updated: 2023/05/19 16:45:06 by maderuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <fract_ol.h>

int	key_hook(int keycode, t_ref *ref)
{
	if (keycode == K_ESC)
		end_prog(ref);
	else if (keycode == K_C)
		update_colors(ref);
	key_move(keycode, ref);
	return (0);
}

void	key_move(int key, t_ref *ref)
{
	float	w;
	float	h;

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
	return (0);
}

/*int	mos_mov(int x, int y, t_ref *ref)
{

}*/
