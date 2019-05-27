/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_backtrack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsomvil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 11:57:12 by alsomvil          #+#    #+#             */
/*   Updated: 2018/01/08 12:41:23 by alsomvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_isempty(char **area, char **tab, int x, int y)
{
	int	i;
	int	j;
	int len;

	i = 0;
	j = 0;
	len = ft_strlen(area[0]) - 1;
	while (tab[i])
	{
		if ((y + i) > len)
			return (0);
		while (tab[i][j])
		{
			if ((x + j) > len)
				return (0);
			if (tab[i][j] == '#' && area[y + i][x + j] != '.')
				return (0);
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

char	**ft_puttetri(char **area, char **tab, char c, int pos)
{
	int	i;
	int	j;
	int x;
	int y;

	i = 0;
	j = 0;
	x = pos % ft_strlen(area[0]);
	y = pos / ft_strlen(area[0]);
	while (tab[i] && area[y + i])
	{
		while (tab[i][j] && area[y + i][x + j])
		{
			if (tab[i][j] == '#' && area[y + i][x + j] == '.')
				area[y + i][x + j] = 'A' + c;
			j++;
		}
		j = 0;
		i++;
	}
	return (area);
}

char	**ft_deltetri(char **area, int i)
{
	int	j;
	int	k;

	j = 0;
	k = 0;
	while (area[j])
	{
		while (area[j][k])
		{
			if (area[j][k] == ('A' + i))
				area[j][k] = '.';
			k++;
		}
		k = 0;
		j++;
	}
	return (area);
}

int		ft_backtracking(char ***area, char ***tab, int i)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (!tab[i])
		return (1);
	while ((*area)[y] != NULL)
	{
		while ((*area)[y][x])
		{
			if (ft_isempty(*area, tab[i], x, y))
			{
				ft_puttetri(*area, tab[i], i, (y * ft_strlen(*(area)[0]) + x));
				if (ft_backtracking(area, tab, i + 1))
					return (1);
				ft_deltetri(*area, i);
			}
			x++;
		}
		x = 0;
		y++;
	}
	return (0);
}
