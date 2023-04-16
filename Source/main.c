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

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->ll + x * (data->bpp / 8));
       *(unsigned int*)dst = color;	
}

int	close(int keycode, d_mlx *var)
{
	mlx_destroy_window(var->mlx, var->win);
	return (0);
}

int	main(void)
{
	d_mlx	*win;
	t_data	*img;
	int	i;

	i = 0;
	win = malloc(sizeof(d_mlx));
	img = malloc(sizeof(t_data));
	win->mlx = mlx_init();
	win->win = mlx_new_window(win->mlx, 500, 500, "win");
	img->img = mlx_new_image(win->mlx, 300, 300);
	img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->ll, &img->end);
	while (i++ < 300)
		my_mlx_pixel_put(img, 310, i, 0x00FF0000);
	mlx_put_image_to_window(win->mlx, win->win, img->img, 0, 0);
	mlx_hook(win->win, 2, 1L<<0, close, &win);
	mlx_loop(win->mlx);
	free(win);
	free(img);
	return (0);
}
