/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filecpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbruvry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 18:30:11 by hbruvry           #+#    #+#             */
/*   Updated: 2018/01/08 12:41:41 by alsomvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	***ft_moveup(char ***tab)
{
	int i;
	int j;

	i = 0;
	j = -1;
	while (tab[i])
	{
		while (!ft_strcmp(tab[i][0], "...."))
		{
			while (j++ < 2)
				tab[i][j] = ft_strdup(tab[i][j + 1]);
			tab[i][3] = ft_strdup("....");
			j = -1;
		}
		i++;
	}
	return (tab);
}

char	***ft_moveleft(char ***tab)
{
	int	i;
	int	j;

	i = 0;
	j = -1;
	while (tab[i])
	{
		while (tab[i][0][0] == '.' && tab[i][1][0] == '.'
			&& tab[i][2][0] == '.' && tab[i][3][0] == '.')
		{
			while (j++ < 3)
			{
				tab[i][j] = ft_strdup(tab[i][j] + 1);
				tab[i][j][3] = '.';
			}
			j = -1;
		}
		i++;
	}
	return (tab);
}

char	***ft_stock(char ***tab, char *file, int nb)
{
	int		i;
	int		fd;
	char	buf[22];

	i = 0;
	ft_bzero(buf, 21);
	if (nb == -1 || (fd = open(file, O_RDONLY)) == -1)
	{
		ft_putstr("error\n");
		return (NULL);
	}
	while (read(fd, buf, 21) > 0)
	{
		tab[i] = ft_strsplit(buf, '\n');
		if (!tab[i][0] || !tab[i][1] || !tab[i][2] || !tab[i][3]
			|| (i == nb && buf[20] == '\n'))
		{
			ft_putstr("error\n");
			return (NULL);
		}
		ft_bzero(buf, 21);
		i++;
	}
	tab[i] = NULL;
	return (tab);
}

char	***ft_tabtrim(char ***tab)
{
	int	i;
	int	j;
	int	k;

	i = -1;
	j = 4;
	k = 3;
	while (tab[++i])
	{
		while (tab[i][--j] && j >= 0)
		{
			if (!ft_strcmp(tab[i][j], "...."))
				ft_strdel(&tab[i][j]);
			else
			{
				while (tab[i][j][k] == '.')
					k--;
				if (k != 3)
					tab[i][j] = ft_strsub(tab[i][j], 0, k + 1);
			}
			k = 3;
		}
		j = 4;
	}
	return (tab);
}

char	***ft_filecpy(char *file)
{
	int		fd;
	int		nb;
	char	buf[22];
	char	***tab;

	nb = 0;
	ft_bzero(buf, 21);
	if ((fd = open(file, O_RDONLY)) == -1)
		return (NULL);
	while (read(fd, buf, 21) > 0)
	{
		if (!ft_checkerror(buf))
			return (NULL);
		nb++;
	}
	if (!(tab = ft_memalloc(sizeof(char **) * nb)) || close(fd) == -1)
		return (NULL);
	fd = 0;
	while (fd < nb)
		if (!(tab[fd++] = ft_memalloc(sizeof(char *) * 5)))
			return (NULL);
	if (!(tab = ft_stock(tab, file, nb - 1)))
		return (NULL);
	tab = ft_tabtrim(ft_moveup(ft_moveleft(tab)));
	return (tab);
}
