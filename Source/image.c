#include <fract_ol>

s_img	*init_img(s_mlx *mlx)
{
	s_img	*img;

	img = malloc(sizeof(s_img));
	img->img = mlx_new_image(mlx->ptr, LF, HF);
	img->ptr = mlx_get_data_addr(img->img, &img->bpp, &img->lil, &img->end);
	my_pixel_put(img, LF/2, HF/2, 0x00FF0000);
	return (img);
}

