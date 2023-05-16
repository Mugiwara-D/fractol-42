/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maderuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 14:24:50 by maderuel          #+#    #+#             */
/*   Updated: 2023/05/12 14:24:07 by maderuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H

# define LF 1920
# define HF 1080

# include <../minilibx-linux/mlx.h>
# include <stdlib.h>
# include <ft_printf.h>
# include <libft.h>

typedef struct s_complex
{
	double	r;
	double	i;
}	t_complex;

typedef struct pixel_data
{
	int32_t	x;
	int32_t	y;
	int32_t	color;
}	t_pxl;

typedef struct img_data
{
	void	*img;
	char	*ptr;
	int		bpp;
	int		lil;
	int		end;
}	t_img;

typedef struct mlx_data
{
	void	*ptr;
	void	*win;
	t_img	img;
}	t_mlx;

typedef struct s_view
{
	float	zx;
	float	zy;
	float	mz;
}	t_view;

typedef struct s_fscope
{	
	float	ymax;
	float	xmax;
	float	ymin;
	float	xmin;
}	t_scope;

typedef struct fractal_data
{
	char		*name;
	t_scope		base;
	t_complex	z;
	t_complex	c;
	int			imax;
	t_view		zoom;
}	t_fractal;

typedef struct s_references
{
	t_mlx		*m;
	t_fractal	*f;
	t_pxl		*p;
}	t_ref;

typedef int	(*t_comp)(t_pxl *,t_fractal *);

void		init_img(t_mlx *mlx);
t_fractal	*init_f(char **args);
void		draw(t_img *frame, t_pxl *p, t_fractal *f, int (*t_comp)(t_pxl *, t_fractal *));
t_mlx		*init_m(void);
int			key_hook(int keycode, t_ref *ref);
void		my_pixel_put(t_img *data, int x, int y, int color);
int			s_cmp(char *s1, char *s2);
int			mandelbrot(t_pxl *p, t_fractal *f);
int			julia(t_pxl *p, t_fractal *f);
void		init_julia(t_fractal *f);
t_fractal		*init_mandelbrot(t_fractal *f);
int			end_prog(t_ref *ref);
int			mos_hook(int btn, int x, int y, t_ref *ref);
void		zoom_in(t_fractal *f, int x, int y);
void		zoom_out(t_fractal *f, int x, int y);
void		render_img(t_fractal *f, t_pxl *p, t_mlx *mlx);
void		ft_exit(t_mlx *m, t_pxl *p, t_fractal *f);
t_complex	screen_to_complex(t_pxl *p, t_fractal *f);
t_img		del_img(t_ref *ref);

#endif
