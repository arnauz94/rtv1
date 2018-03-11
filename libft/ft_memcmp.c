/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avinas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 21:39:26 by avinas            #+#    #+#             */
/*   Updated: 2017/11/16 15:43:44 by avinas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *str1, const void *str2, size_t n)
{
	unsigned char	*s1;
	unsigned char	*s2;
	unsigned long	cpt;
	int				ret;

	s1 = (unsigned char*)str1;
	s2 = (unsigned char*)str2;
	cpt = 0;
	ret = 0;
	if (n < 1)
		return (0);
	while (cpt < n - 1)
	{
		ret = s1[cpt] - s2[cpt];
		if (ret != 0)
			return (ret);
		cpt++;
	}
	if (s1[cpt] != s2[cpt])
	{
		ret = (s1[cpt] != '\0') ? +s1[cpt] : -s2[cpt];
	}
	return (ret);
}
