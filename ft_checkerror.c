/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkerror.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsomvil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 02:55:25 by alsomvil          #+#    #+#             */
/*   Updated: 2018/01/08 12:41:34 by alsomvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_checknbdiese(char *str)
{
	int	i;
	int	nb;

	i = 0;
	nb = 0;
	while (str[i])
	{
		if (str[i] == '#')
			nb++;
		i++;
	}
	if (nb != 4)
		return (1);
	return (0);
}

int		ft_checktetriminos(char *str)
{
	int	i;
	int	link;

	i = 0;
	link = 0;
	if (ft_checknbdiese(str))
		return (1);
	while (str[i])
	{
		if (str[i] == '#')
		{
			if ((i - 5) >= 0 && str[i - 5] == '#')
				link++;
			if ((i + 5) < 21 && str[i + 5] == '#')
				link++;
			if (str[i + 1] == '#')
				link++;
			if (str[i - 1] == '#')
				link++;
		}
		i++;
	}
	if (link == 6 || link == 8)
		return (0);
	return (1);
}

int		ft_checkerror(char *str)
{
	int	i;
	int ret;

	i = 0;
	ret = 1;
	if (str[4] != '\n' || str[9] != '\n' || str[14] != '\n' || str[19] != '\n')
		ret = 0;
	if (ft_checktetriminos(str) == 1)
		ret = 0;
	while (str[i])
	{
		if (str[i] == '\n'
			&& (i != 4 && i != 9 && i != 14 && i != 19 && i != 20))
			ret = 0;
		if (str[i] != '.' && str[i] != '#' && str[i] != '\n' && str[i] != 127)
			ret = 0;
		i++;
	}
	i = 0;
	if (!ret)
		ft_putstr("error\n");
	return (ret);
}
