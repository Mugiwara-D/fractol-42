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
	if (mlx->ptr && mlx->win)
		mlx_destroy_window(mlx->ptr, mlx->win);
	if (mlx->img->ptr && mlx->ptr)
		mlx_destroy_image(mlx->ptr, mlx->img->ptr);
	return(0);
}
