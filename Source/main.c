/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maderuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 13:47:43 by maderuel          #+#    #+#             */
/*   Updated: 2023/04/16 16:11:35 by maderuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <fract_ol.h>

t_mlx_data	*win_del(t_mlx_data *mlx)
{
	if (mlx->win)
		mlx_destroy_window(mlx->ptr, mlx->win);
	return (NULL);
}

t_mlx_data	*init()
{
	t_mlx_data	*mlx;

	mlx = malloc(sizeof(t_mlx_data));
	if (!mlx)
		return (NULL);
	mlx->ptr = mlx_init();
	mlx->win = mlx_new_window(mlx->ptr, 960, 540, "fract-ol");
	return (mlx);
}

int	main(void)
{
	t_mlx_data	*mlx;

	mlx = init();
	mlx_loop(mlx->ptr);
	free(mlx);
	return (0);
}
