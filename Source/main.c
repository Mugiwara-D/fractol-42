/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maderuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 13:47:43 by maderuel          #+#    #+#             */
/*   Updated: 2023/05/05 16:33:09 by maderuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <fract_ol.h>

int	check_args(char **arg)
{
	if (s_cmp(arg[1], "mandelbrot") || s_cmp(arg[1], "julia") || s_cmp(arg[1], "j"))
		return (0);
	return (1);
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
	t_ref		*ref;

	(void) ac;
	if (check_args(av))
	{
		ft_printf("bad");
		return (0);
	}
	pxl = malloc(sizeof(t_pxl));
	ref = malloc(sizeof(t_ref));
	f = init_f(av);
	mlx = init_m();
	ref->m = mlx;
	ref->f = f;
	ref->p = pxl;
	render_img(f, pxl, mlx);
	mlx_key_hook(mlx->win, key_hook, ref);
	//mlx_mouse_hook(mlx->win, mos_hook, ref);
	mlx_hook(mlx->win, 4, 1L << 2, mos_hook, ref);
	mlx_loop(mlx->ptr);
	return (0);
}
