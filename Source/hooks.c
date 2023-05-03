#include <fract_ol.h>

int	key_hook(int keycode, t_mlx *mlx)
{
	if (keycode == 65307)
		mlxclean(mlx);
	else if (keycode == 65362)
		ft_bzero(mlx, sizeof(t_mlx));

	return (0);
}

int	mos_hook(int btn, int x, int y, t_fractal *f, t_pxl *p, t_mlx *mlx)
{
	if (btn == 4)
	{
		zoom_in(f);
		init_img(mlx);
		render_img(f, p, mlx);
	}
	return (0);

}
