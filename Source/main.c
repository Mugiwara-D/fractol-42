/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maderuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 13:47:43 by maderuel          #+#    #+#             */
/*   Updated: 2023/04/24 16:07:10 by maderuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <fract_ol.h>

int	check_arg(char **args)
{

	return (s_cmp(args[1], "madelbrot"));
}

int	main(int ac, char **av)
{
	t_mlx	*mlx;
	t_img	*img;
	t_pxl	*pxl;

	if (check_arg(av))
		return (0 * ft_printf("bad entries, try with:\nmandelbrot\njulia + specification"));
	mlx = init();
	img = init_img(mlx);
	pxl = malloc(sizeof(t_pxl));
	draw(img, pxl);
	mlx_hook(mlx->win, 2, 1L<<0, key_hook, &mlx);
	mlx_put_image_to_window(mlx->ptr, mlx->win, img->img, 0, 0);
	mlx_loop(mlx->ptr);
	free(mlx);
	free(img);
	free(pxl);
	return (0);
}
