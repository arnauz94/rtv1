/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avinas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 19:49:15 by avinas            #+#    #+#             */
/*   Updated: 2017/11/19 16:31:44 by avinas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char const *s)
{
	int cpt;

	cpt = 0;
	while (s[cpt])
	{
		cpt++;
	}
	write(1, s, cpt);
}