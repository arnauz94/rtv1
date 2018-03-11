#include "../include/rtv1.h"
#include "../include/get_next_line.h"

void		init_env(t_env *e)
{
	e->bpp = 8;
	e->sizl = 8;
	e->endian = 0;
}

t_obj		get_obj(char *line)
{
	char	**tab
	int		cpt;
	t_obj	ret;

	tab = ft_strsplit(line, ' ');
	
	if (!ft_strcmp(tab[0], "CAM"))
	{
		ret.type = tab[0];

		ret.pos.x = atoi(tab[2]);
		ret.pos.y = atoi(tab[3]);
		ret.pos.z = atoi(tab[4]);

		ret.rot.x = atoi(tab[6]);
		ret.rot.y = atoi(tab[7]);
		ret.rot.z = atoi(tab[8]);
	}
	else if (!ft_strcmp(tab[0], "SPHERE"))
	{
		ret.type = tab[0];

		ret.pos.x = atoi(tab[2]);
		ret.pos.y = atoi(tab[3]);
		ret.pos.x = atoi(tab[4]);

		ret.size = atoi(tab[6]);

		ret.col.r = atoi(tab[8]);
		ret.col.g = atoi(tab[9]);
		ret.col.b = atoi(tab[10]);
	}
}

t_env		add_obj(char *line, t_env e)
{
	t_obj obj;

	obj = get_obj(line);
	return (e);
}

t_env		read_file(t_env e, char *file)
{
	int     fd;
	char    *line;
	int     nbline;

	nbline = 0;
	fd = open(file, O_RDONLY);
	while (get_next_line(fd, &line) == 1)
	{
		e = add_obj(line, t_env e);
		ft_strdel(&line);
		nbline++;
	}
	ft_strdel(&line);
	fd = 0;
	return (e);
}

int			main(int argc, char **argv)
{
	t_env	e;

	if (argc != 2)
	{
		ft_putstr("need file");
		return (0);
	}

	e.mlx_ptr = mlx_init();
	e.win_ptr = mlx_new_window(e.mlx_ptr, WIN_LARGE, WIN_HAUT, "rtv1");
	e.img_ptr = mlx_new_image(e.mlx_ptr, WIN_LARGE, WIN_HAUT);
	e.img_data = (int*)mlx_get_data_addr(e.img_ptr, &e.bpp, &e.sizl, &e.endian);
	e = read_file(e, argv[1]);
	mlx_loop(e.mlx_ptr);
}
