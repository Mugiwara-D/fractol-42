#ifndef FRACT_OL_H
# define FRACT_OL_H

# define LF 1280
# define HF 720

# include <../minilibx-linux/mlx.h>
# include <stdlib.h>

typedef	struct	mlx_data
{
	void	*ptr;
	void	*win;

}	s_mlx;

typedef	struct t_complex
{
	double	rel;
	double	ima;
}	s_complex;

typedef struct	pixel_data
{
	int32_t	x;
	int32_t	y;
	int32_t color;
}	s_pxl;

typedef	struct	img_data
{
	void	*img;
	char	*ptr;
	int	bpp;
	int	lil;
	int	end;
}	s_img;

typedef struct	fractal_data
{
	char *name;
	
}	s_fractal;

s_img	*init_img(s_mlx *mlx);
void	draw(s_img *frame, s_pxl *p);
s_mlx	*init();
int	key_hook(int keycode, s_mlx *mlx);
void    my_pixel_put(s_img *data, int x, int y, int color);

#endif
