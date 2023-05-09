/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maderuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 14:26:30 by maderuel          #+#    #+#             */
/*   Updated: 2023/05/09 14:38:32 by maderuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fract_ol.h>

int	s_cmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (!s1 || !s2)
		return (-1);
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return (1);
		i++;
	}
	return (0);
}

int	end_prog(t_ref *ref)
{
	if (ref->m->img.img && ref->m->ptr)
		mlx_destroy_image(ref->m->ptr, ref->m->img.img);
	if (ref->m->ptr && ref->m->win)
		mlx_destroy_window(ref->m->ptr, ref->m->win);
	if (ref->m->ptr)
		mlx_destroy_display(ref->m->ptr);
	if (ref->m->ptr)
		free(ref->m->ptr);
	if (ref->m)
		free(ref->m);
	if (ref->f)
		free(ref->f);
	if (ref->p)
		free(ref->p);
	if (ref)
		free(ref);
	exit (0);
}

