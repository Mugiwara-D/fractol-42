#include <fract_ol.h>

int	key_hook(int keycode, s_mlx *mlx)
{
	if (keycode == 65307)
		mlx_destroy_window(mlx->ptr, mlx->win);
	return (0);
}
