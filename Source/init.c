/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maderuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 14:36:07 by maderuel          #+#    #+#             */
/*   Updated: 2023/05/22 14:44:42 by maderuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fract_ol.h>

void	init_img(t_mlx *mlx)
{
	mlx->img.img = mlx_new_image(mlx->ptr, LF, HF);
	mlx->img.ptr = mlx_get_data_addr(mlx->img.img,
			&mlx->img.bpp, &mlx->img.lil, &mlx->img.end);
}

t_mlx	*init_m(void)
{
	t_mlx	*mlx;

	mlx = malloc(sizeof(t_mlx));
	if (!mlx)
		return (NULL);
	mlx->ptr = mlx_init();
	if (mlx->ptr == NULL)
		return (NULL);
	mlx->win = mlx_new_window(mlx->ptr, LF, HF, "fract-ol");
	if (mlx->win == NULL)
		return (NULL);
	init_img(mlx);
	return (mlx);
}

t_fractal	*init_f(char **args)
{
	t_fractal	*f;

	f = calloc(1, sizeof(t_fractal));
	if (!f)
		return (NULL);
	if (!s_cmp(args[1], "mandelbrot") || !s_cmp(args[1], "m"))
	{
		f->name = "mandelbrot";
		f = init_mandelbrot(f);
		return (f);
	}
	else if (!s_cmp(args[1], "julia") || !s_cmp(args[1], "j"))
	{	
		f->name = "julia";
		init_julia(f, args[2]);
		return (f);
	}
	else if (!s_cmp(args[1], "burning_ship") || !s_cmp(args[1], "b"))
	{	
		f->name = "burning_ship";
		init_bns(f);
		return (f);
	}
	return (f);
}
