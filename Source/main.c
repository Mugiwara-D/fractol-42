/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maderuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 13:47:43 by maderuel          #+#    #+#             */
/*   Updated: 2023/05/05 15:58:46 by maderuel         ###   ########.fr       */
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
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img.img, LF/4, HF/4);
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
	pxl = malloc(sizeof(t_pxl));
	f = init_f(av);
	mlx = init_m();
	render_img(f, pxl, mlx);
	mlx_key_hook(mlx->win, key_hook, mlx);
	mlx_loop(mlx->ptr);
	free(pxl);
	free(f);
	return (0);
}
