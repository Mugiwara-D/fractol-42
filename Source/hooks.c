/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maderuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 14:04:54 by maderuel          #+#    #+#             */
/*   Updated: 2023/05/11 15:02:11 by maderuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <fract_ol.h>

int	key_hook(int keycode, t_ref *ref)
{
	if (keycode == 65307)
		end_prog(ref);
	return (0);
}

int	mos_hook(int btn, int x, int y, t_ref *ref)
{	
	if (btn == 4)
	{
		zoom_in(ref->f, x, y);
		ft_bzero(&ref->m->img, sizeof(t_img));
		init_img(ref->m);
		render_img(ref->f, ref->p, ref->m);
	}
	else if (btn == 5)
	{
		zoom_out(ref->f, x, y);
		ft_bzero(&ref->m->img, sizeof(t_img));
		init_img(ref->m);
		render_img(ref->f, ref->p, ref->m);
	}
	return (0);
}
