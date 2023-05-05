/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maderuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 14:26:30 by maderuel          #+#    #+#             */
/*   Updated: 2023/05/05 16:17:25 by maderuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fract_ol.h>

int	s_cmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (!s1 || !s2)
		return (-1);
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
		mlx_destroy_image(mlx->ptr, mlx->img.img);
	if (mlx->ptr && mlx->win)
		mlx_destroy_window(mlx->ptr, mlx->win);
	if (mlx->ptr)
		mlx_destroy_display(mlx->ptr);
	if (mlx->ptr)
		free(mlx->ptr);
	if (mlx)
		free(mlx);
	exit (0);
}
