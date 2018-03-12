#include "../include/rtv1.h"

void		init_env(t_env *e)
{
	e->bpp = 8;
	e->sizl = 8;
	e->endian = 0;
	e->nbobj = 2;
	e->tabobj = (t_obj*)malloc(sizeof(t_obj) * 2);
	e->tabobj[0].type = 0;
	e->tabobj[0].rot.x = 5;
	e->tabobj[0].rot.y = -10;
	e->tabobj[0].rot.z = 5;
	e->tabobj[0].pos.x = 50;
	e->tabobj[0].pos.y = 10;
	e->tabobj[0].pos.z = 0;

	e->tabobj[1].type = 1;
	e->tabobj[1].pos.x = 0;
	e->tabobj[1].pos.y = 0;
	e->tabobj[1].pos.z = 0;
	e->tabobj[1].size = 5;
	e->tabobj[1].color.r = 255;
	e->tabobj[1].color.g = 0;
	e->tabobj[1].color.b = 0;
}

t_color		get_pixel_color(t_env e, int x, int y)
{
	t_color	color;
	int		cpt;
	float	a;
	float	b;
	float	c;
	float	delta;
		
	color.r	= 0;
	cpt = 1;
	while(cpt < e.nbobj)
	{
		a = pow(e.tabobj[0].rot.x + x, 2) + pow(e.tabobj[0].rot.y + y, 2) + pow(e.tabobj[0].rot.z, 2);
		b = 2 * (e.tabobj[0].rot.x + x  * (e.tabobj[0].pos.x - e.tabobj[cpt].pos.x)
				+ e.tabobj[0].rot.y + y * (e.tabobj[0].pos.y - e.tabobj[cpt].pos.y)
				+ e.tabobj[0].rot.z * (e.tabobj[0].pos.z - e.tabobj[cpt].pos.z));
		c = (pow(e.tabobj[0].pos.x - e.tabobj[cpt].pos.x, 2)
			+ pow(e.tabobj[0].pos.y - e.tabobj[cpt].pos.y, 2)
			+ pow(e.tabobj[0].pos.z - e.tabobj[cpt].pos.z, 2)) - pow(e.tabobj[cpt].size, 2);
		delta = pow(b, 2) - 4 * a * c;
		
		if (delta >= 0)
			color.r = 255;
		cpt++;
	}
	return (color);
}

t_env		render(t_env e)
{
	int			x;
	int			y;
	t_color		color;

	int			cpt;
	cpt = 0;
	
	x = 0;
	y = 0;
	while (y < WIN_HAUT)
	{
		x = 0;
		while (x < WIN_LARGE)
		{
			color = get_pixel_color(e, x, y);
			e.img_data[y * WIN_LARGE + x] = color.r;
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(e.mlx_ptr, e.win_ptr, e.img_ptr, 0, 0);
	return (e);
}

int			main()
{
	t_env	e;

	init_env(&e);
	e.mlx_ptr = mlx_init();
	e.win_ptr = mlx_new_window(e.mlx_ptr, WIN_LARGE, WIN_HAUT, "rtv1");
	e.img_ptr = mlx_new_image(e.mlx_ptr, WIN_LARGE, WIN_HAUT);
	e.img_data = (int*)mlx_get_data_addr(e.img_ptr, &e.bpp, &e.sizl, &e.endian);
	e = render(e);
	mlx_loop(e.mlx_ptr);
}
