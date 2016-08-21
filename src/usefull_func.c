/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usefull_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avella <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 15:14:16 by avella            #+#    #+#             */
/*   Updated: 2016/03/15 15:20:20 by avella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		my_expose(t_struct *mystruct)
{
	mlx_put_image_to_window(mystruct->mlx, mystruct->win,
			mystruct->img->img_ptr, 0, 0);
	return (0);
}

void	give_map_to_struct(char *line, t_struct *mystruct)
{
	int i;
	int x;
	int y;

	i = 0;
	x = 0;
	y = 0;
	while (line[i] != '\0')
	{
		mystruct->worldmap[y][x] = line[i] - '0';
		if (line[i] == '\n')
		{
			y++;
			x = 0;
		}
		else
			x++;
		i++;
	}
}

char	*my_maps(void)
{
	char	*line;
	char	*yt;
	int		fd;
	int		ret;

	fd = 0;
	ret = 0;
	fd = open("map", O_RDONLY);
	line = (char *)malloc(sizeof(char) * 2);
	while ((ret = get_next_line(fd, &yt)) && ret != -1)
	{
		line = ft_strjoins(line, yt);
		line = ft_strjoins(line, "\n");
	}
	if (ret == -1 || line[0] == '\0')
	{
		ft_putstr("Bad file descriptor\n");
		exit(1);
	}
	return (line);
}

void	gotet(t_struct *mystruct)
{
	int		i;
	t_temp	*coord;

	i = 840;
	while (i < 890)
	{
		coord = give_temp(840, i, 890, i);
		what_a_pro_draw(coord, mystruct, 0xFFFFFF);
		i++;
	}
}
