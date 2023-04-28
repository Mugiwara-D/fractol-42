/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maderuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 13:47:43 by maderuel          #+#    #+#             */
/*   Updated: 2023/04/28 15:45:00 by maderuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <fract_ol.h>

t_fractal	init_f(char **args)
{
	t_fractal	f;

	if (s_cmp(args[1], "mandelbrot") || args[1][0] == 'm')
		f.name = "mandelbrot";
	else if (s_cmp(args[1], "julia"))
		f.name = "julia";
	return (f);
}

int	check_args(char **arg)
{
	return (s_cmp(arg[1], "mandelbrot") + s_cmp(arg[1], "julia"));
}

int	main(int ac, char **av)
{
	t_mlx	*mlx;
	t_img	*img;
	t_pxl	*pxl;

	mlx = init();
	img = init_img(mlx);
	pxl = malloc(sizeof(t_pxl));
	draw(img, pxl);
	mlx_hook(mlx->win, 2, 1L << 0, key_hook, &mlx);
	mlx_put_image_to_window(mlx->ptr, mlx->win, img->img, 0, 0);
	mlx_loop(mlx->ptr);
	free(mlx);
	free(img);
	free(pxl);
	return (0);
}
