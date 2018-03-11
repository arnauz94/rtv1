#ifndef FRACTOL_H
# define FRACTOL_H

# include "../minilibx_macos/mlx.h"
# include "../libft/libft.h"
# include <math.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>

# define WIN_LARGE 400
# define WIN_HAUT 400

typedef struct	s_env
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	int			*img_data;
	int			bpp;
	int			sizl;
	int			endian;
	t_obj		*listobj;
}				t_env;

typedef struct		s_color
{
	float			r;
	float			g;
	float			b;
}					t_color;

typedef struct		s_obj
{
	int				type;
	float			size;
	t_vec			rot;
	t_vec			pos;
	t_color			col;
	struct s_obj	*next;
}					t_obj;

typedef struct		s_vec
{
	float			x;
	float			y;
	float			z;
}					t_vec;

#endif
