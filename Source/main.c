/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maderuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 13:47:43 by maderuel          #+#    #+#             */
/*   Updated: 2023/05/03 15:03:59 by maderuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <fract_ol.h>

int	check_args(char **arg)
{
	return (s_cmp(arg[1], "mandelbrot"));
}

void	render_img(t_fractal *f, t_pxl *p, t_mlx *mlx)
{
	if (!s_cmp(f->name, "mandelbrot"))
		draw(&mlx->img, p, f, &mandelbrot);
	else if (!s_cmp(f->name, "julia"))
		draw(&mlx->img, p, f, &julia);
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img.img, 0, 0);
}

int	main(int ac, char **av)
{
	t_mlx		*mlx;
	t_pxl		*pxl;
	t_fractal	*f;

	(void) ac;
	if (check_args(av))
	{
		ft_printf("bad");
		return (0);
	}
	f = init_f(av);
	mlx = init_m();
	init_img(mlx);
	pxl = malloc(sizeof(t_pxl));
	mlx_hook(mlx->win, 2, 1L << 0, key_hook, &mlx);
	mlx_mouse_hook(mlx->win, mos_hook, &mlx);
	render_img(f, pxl, mlx);
	mlx_loop(mlx->ptr);
	free(pxl);
	free(f);
	return (0);
}
