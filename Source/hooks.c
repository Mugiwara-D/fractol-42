/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maderuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 14:04:54 by maderuel          #+#    #+#             */
/*   Updated: 2023/05/04 15:30:13 by maderuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fract_ol.h>

int	key_hook(int keycode, t_mlx *mlx)
{
	if (keycode == 65307)
		mlxclean(mlx);
	return (0);
}

int	mos_hook(int btn, int x, int y, t_fractal *f, t_pxl *p, t_mlx *mlx)
{
	(void) x;
	(void) y;
	if (btn == 4)
	{
		zoom_in(f);
		init_img(mlx);
		render_img(f, p, mlx);
	}
	return (0);

}
