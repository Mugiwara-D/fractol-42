#include <fract_ol.h>

int	key_hook(int keycode, t_mlx *mlx)
{
	if (keycode == 65307)
		mlxclean(mlx);

	return (0);
}

int	mos_hook(int btn, int x, int y, t_fractal *f, t_pxl *p, t_mlx *mlx)
{
	if (btn == 4)
	{
		zoom_in(f);
		render_img(f, p, mlx);
	}
	return (0);

}
