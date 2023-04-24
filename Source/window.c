#include <fract_ol.h>

t_mlx	*init()
{
	t_mlx	*mlx;

	mlx = malloc(sizeof(t_mlx));
	if (!mlx)
		return (NULL);
	mlx->ptr = mlx_init();
	mlx->win = mlx_new_window(mlx->ptr, LF, HF, "fract-ol");
	return (mlx);
}


