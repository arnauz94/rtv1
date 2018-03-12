/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readfile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avinas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 10:28:04 by avinas            #+#    #+#             */
/*   Updated: 2018/03/12 15:04:07 by avinas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rtv1.h"
#include "../include/get_next_line.h"

t_obj           get_obj(char *line)
{
	char    **tab;
	t_obj   ret;

	tab = ft_strsplit(line, ' ');

	if (!ft_strcmp(tab[0], "CAM"))
	{
		ret.type = "CAM\0";

		ret.pos.x = atoi(tab[2]);
		ret.pos.y = atoi(tab[3]);
		ret.pos.z = atoi(tab[4]);

		ret.rot.x = atoi(tab[6]);
		ret.rot.y = atoi(tab[7]);
		ret.rot.z = atoi(tab[8]);
	}
	else if (!ft_strcmp(tab[0], "SPHERE"))
	{
		ret.type = "SPHERE\0";

		ret.pos.x = atoi(tab[2]);
		ret.pos.y = atoi(tab[3]);
		ret.pos.x = atoi(tab[4]);

		ret.size = atoi(tab[6]);

		ret.col.r = atoi(tab[8]);
		ret.col.g = atoi(tab[9]);
		ret.col.b = atoi(tab[10]);
	}
	else
	{
		ret.type = "NOPE";
	}
	return (ret);
}

t_obj           *add_obj(t_obj *tabobj, t_obj obj, int nbline)
{
	t_obj	tab[nbline + 1];
	t_obj	*ret;
	int		cpt;
	
	cpt = 0;
	while (cpt < nbline)
	{
		tab[cpt] = tabobj[cpt];
		ft_putnbr(cpt);
	ft_putstr(tabobj[0].type);
	ft_putstr("\n");
		cpt++;
	}
	tab[cpt] = obj;
	ret = &tab[0];
	return (ret);
}

t_env           read_file(t_env e, char *file)
{
	int     fd;
	char    *line;
	t_obj	tmp;
	int     nbline;

	nbline = 0;
	fd = open(file, O_RDONLY);
	while (get_next_line(fd, &line) == 1)
	{
		tmp = get_obj(line);
		e.tabobj = add_obj(e.tabobj, tmp, nbline);
		nbline++;
	}
	fd = 0;
	return (e);
}
