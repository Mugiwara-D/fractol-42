#include <fract_ol.h>

void	my_pixel_put(s_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->ptr + (y * data->lil + x * (data->bpp / 8));
       *(unsigned int*)dst = color;	
}

