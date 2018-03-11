#include "../include/rtv1.h"

int			main()
{
	t_env	e;

	e.mlx_ptr = mlx_init();
	e.win_ptr = mlx_new_window(e.mlx_ptr, WIN_LARGE, WIN_HAUT, "rtv1");
	e.img_ptr = mlx_new_image(e.mlx_ptr, WIN_LARGE, WIN_HAUT);
	e.img_data = (int*)mlx_get_data_addr(e.img_ptr, &e.bpp, &e.sizl, &e.endian);
	mlx_loop(e.mlx_ptr);
}
