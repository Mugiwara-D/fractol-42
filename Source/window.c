#include <fract_ol>

s_mlx	*init()
{
	s_mlx	*mlx;

	mlx = malloc(sizeof(s_mlx));
	if (!mlx)
		return (NULL);
	mlx->ptr = mlx_init();
	mlx->win = mlx_new_window(mlx->ptr, LF, HF, "fract-ol");
	return (mlx);
}


