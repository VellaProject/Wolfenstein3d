/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avella <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 16:43:07 by avella            #+#    #+#             */
/*   Updated: 2016/03/15 15:02:21 by avella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	hit_or_no(t_inwolf *w, t_struct *mystruct)
{
	while (w->hit == 0)
	{
		if (w->sidedistx < w->sidedisty)
		{
			w->sidedistx += w->deltadistx;
			w->mapx += w->stepx;
			w->side = 0;
		}
		else
		{
			w->sidedisty += w->deltadisty;
			w->mapy += w->stepy;
			w->side = 1;
		}
		if (mystruct->worldmap[w->mapx][w->mapy] > 0)
			w->hit = 1;
	}
	if (w->side == 0)
		w->perpwalldist = (w->mapx - w->rayposx +
				(1 - w->stepx) / 2) / w->raydirx;
	else
		w->perpwalldist = (w->mapy - w->rayposy +
				(1 - w->stepy) / 2) / w->raydiry;
}

void	last_var_give(t_inwolf *w)
{
	w->lineheight = (int)(HEIGHT / w->perpwalldist);
	w->drawstart = -w->lineheight / 2 + HEIGHT / 2;
	if (w->drawstart < 0)
		w->drawstart = 0;
	w->drawend = w->lineheight / 2 + HEIGHT / 2;
	if (w->drawend >= HEIGHT)
	{
		w->drawend = HEIGHT - 1;
	}
	else if (w->drawend <= 0)
	{
		w->drawend = 1;
	}
}

void	color_choice_yes(t_inwolf *w, t_struct *mystruct)
{
	w->color = 0;
	if (mystruct->worldmap[w->mapx][w->mapy] == 1)
		w->color = 0xFF0000;
	else if (mystruct->worldmap[w->mapx][w->mapy] == 2)
		w->color = 0xFFFFFF;
	else if (mystruct->worldmap[w->mapx][w->mapy] == 3)
		w->color = 0x0045FF;
	else if (mystruct->worldmap[w->mapx][w->mapy] == 4)
		w->color = 0xFFFFFF;
	else if (mystruct->worldmap[w->mapx][w->mapy] == 9)
		w->color = 0x000000;
	else
		w->color = 0x00FFFF;
	if (w->side == 1)
		w->color = w->color / 2;
}

void	side_used(t_inwolf *w, t_struct *mystruct)
{
	if (mystruct->worldmap[w->mapx][w->mapy] == 8)
	{
		if (w->side == 0)
		{
			if (w->stepx < 0)
				w->color = 0xFF0000;
			else
				w->color = 0xFFFF00;
		}
		else
		{
			if (w->stepy < 0)
				w->color = 0x0000FF;
			else
				w->color = 0x00FF00;
		}
	}
}

void	draw2(t_struct *mystruct)
{
	t_inwolf	*w;
	t_temp		*coordsky;
	t_temp		*coordwall;
	t_temp		*coordfloor;

	w = (t_inwolf *)malloc(sizeof(t_inwolf) * 1);
	w_early_give(w, mystruct);
	while (w->x < WIDTH)
	{
		w_inwhile_give(w);
		use_dir(w);
		hit_or_no(w, mystruct);
		last_var_give(w);
		color_choice_yes(w, mystruct);
		side_used(w, mystruct);
		coordsky = give_temp(w->x, 10, w->x, w->drawstart);
		what_a_pro_draw(coordsky, mystruct, 0x00F0F0);
		coordwall = give_temp(w->x, w->drawstart, w->x, w->drawend);
		what_a_pro_draw(coordwall, mystruct, w->color);
		coordfloor = give_temp(w->x, w->drawend, w->x, HEIGHT - 2);
		what_a_pro_draw(coordfloor, mystruct, 0x0000FF / 3);
		w->x++;
	}
}
