/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maderuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 13:47:43 by maderuel          #+#    #+#             */
/*   Updated: 2023/04/24 16:07:10 by maderuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <fract_ol.h>

int	main(void)
{
	t_mlx	*mlx;
	t_img	*img;
	t_pxl	*pxl;

	mlx = init();
	img = init_img(mlx);
	pxl = malloc(sizeof(t_pxl));
	draw(img, pxl);
	mlx_hook(mlx->win, 2, 1L<<0, key_hook, &mlx);
	mlx_put_image_to_window(mlx->ptr, mlx->win, img->img, 0, 0);
	mlx_loop(mlx->ptr);
	free(mlx);
	free(img);
	free(pxl);
	return (0);
}
