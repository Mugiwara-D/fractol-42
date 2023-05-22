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
