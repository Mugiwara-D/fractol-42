/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maderuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 13:47:43 by maderuel          #+#    #+#             */
/*   Updated: 2023/05/16 17:11:00 by maderuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <fract_ol.h>

int	check_args(char **arg)
{
	if (!s_cmp(arg[1], "mandelbrot") || !s_cmp(arg[1], "m")
		|| !s_cmp(arg[1], "julia") || !s_cmp(arg[1], "j"))
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

int	print_notice(void)
{
	ft_printf("you cannot use this program as such.\n"
		"argument must be one the followings :\n"
		"<mandelbrot> or <m> for mandelbrot set\n"
		"<julia> or <j> followed by ... for julia set\n"
		"make sure it lowercase as the dev was to lazy for parsing uppercase\n");
	return (0);
}

void	parse_plus(char **arg)
{
	if (s_cmp(arg[1], "julia") || s_cmp(arg[1], "j"))
	{
		if (s_cmp(arg[2], "1"))
	}
}

int	main(int ac, char **av)
{
	t_mlx		*mlx;
	t_pxl		*pxl;
	t_fractal	*f;
	t_ref		*ref;

	if (check_args(av) || ac < 2 || ac > 3)
		return (print_notice());
	else if (!check_args(av) && ac > 2 && ac < 3)
		parse_plus(av);
	pxl = malloc(sizeof(t_pxl));
	ref = malloc(sizeof(t_ref));
	f = init_f(av);
	mlx = init_m();
	ref->m = mlx;
	ref->f = f;
	ref->p = pxl;
	render_img(f, pxl, mlx);
	mlx_key_hook(mlx->win, key_hook, ref);
	mlx_hook(mlx->win, 4, 1L << 2, mos_hook, ref);
	mlx_hook(mlx->win, 17, 0, end_prog, ref);
	mlx_loop(mlx->ptr);
	return (0);
}
