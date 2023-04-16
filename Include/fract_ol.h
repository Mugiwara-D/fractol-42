#ifndef FRACT_OL_H
# define FRACT_OL_H

# include <../minilibx-linux/mlx.h>
# include <stdlib.h>

typedef	struct	s_mlx
{
	void	*mlx;
	void	*win;

}	d_mlx;

typedef	struct	s_data
{
	void	*img;
	char	*addr;
	int	bpp;
	int	ll;
	int	end;
}	t_data;

#endif
