#include <fract_ol.h>

int	s_cmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return (1);
		i++;
	}
	return (0);
}

int	mlxclean(t_mlx *mlx)
{
	if (mlx->img.img && mlx->ptr)
	{
		mlx_destroy_image(mlx->ptr, mlx->img.img);
		free(mlx->img.img);
		free(mlx->img.ptr);
	}
	if (mlx->ptr)
		mlx_destroy_display(mlx->ptr);
	if (mlx->ptr && mlx->win)
		mlx_destroy_window(mlx->ptr, mlx->win);
	free(mlx->ptr);
	free(mlx->win);
	free(mlx);
	exit (0);
}
