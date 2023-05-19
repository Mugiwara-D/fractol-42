/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maderuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 15:18:22 by maderuel          #+#    #+#             */
/*   Updated: 2023/05/19 16:52:27 by maderuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <fract_ol.h>

int	def(int i)
{
	if (i > 100)
		return (0x00003300);
	else if (i > 75)
		return (0x00FF0000);
	else if (i > 50)
		return (0x00880000);
	else if (i > 25)
		return (0x000000FF);
	else
		return (0x00500000);
}

int	linear(int i)
{
	if (i > 100)
		return (0x0000FF00);
	else if (i > 75)
		return (0x00FF0000);
	else if (i > 50)
		return (0x00880000);
	else if (i > 25)
		return (0x000000FF);
	else
		return (0x00FF0000);
}

int	get_colors(int i, int c)
{
	if (c == 0)
		return (def(i));
	else if (c == 1)
		return (linear(i));
	return (0);
}

void	update_colors(t_ref *ref)
{
	if (ref->f->cop == 2)
		ref->f->cop = 0;
	else
		ref->f->cop++;
	ref->m->img = del_img(ref);
	ft_bzero(&ref->m->img, sizeof(t_img));
	init_img(ref->m);
	render_img(ref->f, ref->p, ref->m);
}
