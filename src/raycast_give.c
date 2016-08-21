/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_give.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avella <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 16:53:05 by avella            #+#    #+#             */
/*   Updated: 2016/03/15 15:03:05 by avella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	w_early_give(t_inwolf *w, t_struct *mystruct)
{
	w->posx = mystruct->wolf->posx;
	w->posy = mystruct->wolf->posy;
	w->dirx = mystruct->wolf->dirx;
	w->diry = mystruct->wolf->diry;
	w->planex = mystruct->wolf->planex;
	w->planey = mystruct->wolf->planey;
	w->time = 0;
	w->oldtime = 0;
	w->x = 0;
}

void	w_inwhile_give(t_inwolf *w)
{
	w->camerax = 2 * w->x / (double)(WIDTH) - 1;
	w->rayposx = w->posx;
	w->rayposy = w->posy;
	w->raydirx = w->dirx + w->planex * w->camerax;
	w->raydiry = w->diry + w->planey * w->camerax;
	w->mapx = (int)w->rayposx;
	w->mapy = (int)w->rayposy;
	w->sidedistx = 0;
	w->sidedisty = 0;
	w->deltadistx = sqrt(1 + (w->raydiry * w->raydiry)
			/ (w->raydirx * w->raydirx));
	w->deltadisty = sqrt(1 + (w->raydirx * w->raydirx)
			/ (w->raydiry * w->raydiry));
	w->perpwalldist = 0;
	w->stepx = 0;
	w->stepy = 0;
	w->hit = 0;
	w->side = 0;
}

void	use_dir(t_inwolf *w)
{
	if (w->raydirx < 0)
	{
		w->stepx = -1;
		w->sidedistx = (w->rayposx - w->mapx) * w->deltadistx;
	}
	else
	{
		w->stepx = 1;
		w->sidedistx = (w->mapx + 1.0 - w->rayposx) * w->deltadistx;
	}
	if (w->raydiry < 0)
	{
		w->stepy = -1;
		w->sidedisty = (w->rayposy - w->mapy) * w->deltadisty;
	}
	else
	{
		w->stepy = 1;
		w->sidedisty = (w->mapy + 1.0 - w->rayposy) * w->deltadisty;
	}
}

void	what_a_pro_draw(t_temp *coord, t_struct *mystruct, int color)
{
	draw_line_on_img(mystruct->img, coord, color);
	free(coord);
}

t_temp	*give_temp(int x1, int y1, int x2, int y2)
{
	t_temp *coord;

	coord = (t_temp *)malloc(sizeof(coord) * 1);
	coord->x1 = x1;
	coord->x2 = x2;
	coord->y1 = y1;
	coord->y2 = y2;
	return (coord);
}
