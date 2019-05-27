/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbruvry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 14:52:26 by hbruvry           #+#    #+#             */
/*   Updated: 2018/01/08 12:41:47 by alsomvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_display(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		ft_putstr(tab[i]);
		ft_putchar('\n');
		i++;
	}
	return ;
}

char	**ft_areanew(int size)
{
	int		i;
	char	**area;

	i = 0;
	if (!(area = ft_memalloc(sizeof(char *) * (size + 1))))
		return (NULL);
	area[size] = NULL;
	while (i < size)
	{
		area[i] = ft_strnew(size);
		ft_memset(area[i], '.', size);
		i++;
	}
	return (area);
}

char	**ft_fillit(char ***tab)
{
	int		i;
	int		nb;
	char	**area;

	i = 0;
	nb = 0;
	while (tab[nb])
		nb++;
	nb = nb * 4;
	while (i * i < nb)
		i++;
	area = ft_areanew(i);
	while (!ft_backtracking(&area, tab, 0))
	{
		i++;
		area = ft_areanew(i);
	}
	return (area);
}

int		main(int argc, char **argv)
{
	char	***tetri;

	if (argc != 2)
	{
		ft_putstr("usage: ./fillit source_file\n");
		return (0);
	}
	else
	{
		if (!(tetri = ft_filecpy(argv[1])))
			return (0);
		ft_display(ft_fillit(tetri));
	}
	return (0);
}
