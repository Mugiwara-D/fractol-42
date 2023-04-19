#include <fract_ol.h>

void	my_pixel_put(t_img_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->ll + x * (data->bpp / 8));
       *(unsigned int*)dst = color;	
}

