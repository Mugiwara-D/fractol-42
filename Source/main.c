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

int	main(void)
{
	s_mlx	*mlx;
	s_img	*img;

	mlx = init();
	img = init_img(mlx);
	mlx_hook(mlx->win, 2, 1L<<0, key_hook, &mlx);
	mlx_put_image_to_window(mlx->ptr, mlx->win, img->img, 0, 0);
	mlx_loop(mlx->ptr);
	free(mlx);
	free(img);
	return (0);
}
