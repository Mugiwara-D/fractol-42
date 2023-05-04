#include <fract_ol.h>

void	init_img(t_mlx *mlx)
{

	mlx->img.img = mlx_new_image(mlx->ptr, LF, HF);
	mlx->img.ptr = mlx_get_data_addr(mlx->img.img, &mlx->img.bpp, &mlx->img.lil, &mlx->img.end);
}

t_mlx	*init_m()
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
	return (mlx);
}

t_fractal	*init_f(char **args)
{
	t_fractal	*f;

	f = malloc(sizeof(t_fractal));
	if (!f)
		return (NULL);
	if (!s_cmp(args[1], "mandelbrot"))
	{
		f->name = "mandelbrot";
		init_mandelbrot(f);
		return (f);
	}
	else if (!s_cmp(args[1], "julia"))
	{	
		f->name = "julia";
		init_julia(f);
		return (f);
	}
	return (f);
}
