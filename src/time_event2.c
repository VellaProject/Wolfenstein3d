/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_event2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avella <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 17:45:33 by avella            #+#    #+#             */
/*   Updated: 2016/03/14 17:46:01 by avella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	yo_right(t_struct *mystruct)
{
	double olddirx;
	double oldplanex;

	olddirx = mystruct->wolf->dirx;
	oldplanex = mystruct->wolf->planex;
	if (mystruct->rightetat == 1)
	{
		mystruct->wolf->dirx = mystruct->wolf->dirx *
			cos(-mystruct->rotspeed) - mystruct->wolf->diry
			* sin(-mystruct->rotspeed);
		mystruct->wolf->diry = olddirx * sin(-mystruct->rotspeed)
			+ mystruct->wolf->diry * cos(-mystruct->rotspeed);
		mystruct->wolf->planex = mystruct->wolf->planex *
			cos(-mystruct->rotspeed) - mystruct->wolf->planey
			* sin(-mystruct->rotspeed);
		mystruct->wolf->planey = oldplanex * sin(-mystruct->rotspeed)
			+ mystruct->wolf->planey * cos(-mystruct->rotspeed);
	}
}

void	my_left_right(t_struct *mystruct)
{
	double olddirx;
	double oldplanex;

	olddirx = mystruct->wolf->dirx;
	oldplanex = mystruct->wolf->planex;
	if (mystruct->leftetat == 1)
	{
		mystruct->wolf->dirx = mystruct->wolf->dirx *
			cos(mystruct->rotspeed) - mystruct->wolf->diry
			* sin(mystruct->rotspeed);
		mystruct->wolf->diry = olddirx * sin(mystruct->rotspeed) +
			mystruct->wolf->diry * cos(mystruct->rotspeed);
		mystruct->wolf->planex = mystruct->wolf->planex *
			cos(mystruct->rotspeed) - mystruct->wolf->planey
			* sin(mystruct->rotspeed);
		mystruct->wolf->planey = oldplanex * sin(mystruct->rotspeed)
			+ mystruct->wolf->planey * cos(mystruct->rotspeed);
	}
	yo_right(mystruct);
}

void	my_up_down(t_struct *mystruct)
{
	if (mystruct->upetat == 1)
	{
		if (mystruct->worldmap[(int)(mystruct->wolf->posx +
					mystruct->wolf->dirx * mystruct->movespeed)]
				[(int)mystruct->wolf->posy] == 0)
			mystruct->wolf->posx += mystruct->wolf->dirx * mystruct->movespeed;
		if (mystruct->worldmap[(int)(mystruct->wolf->posx)]
				[(int)(mystruct->wolf->posy + mystruct->wolf->diry
					* mystruct->movespeed)] == 0)
			mystruct->wolf->posy += mystruct->wolf->diry * mystruct->movespeed;
	}
	if (mystruct->downetat == 1)
	{
		if (mystruct->worldmap[(int)(mystruct->wolf->posx -
					mystruct->wolf->dirx * mystruct->movespeed)]
				[(int)mystruct->wolf->posy] == 0)
			mystruct->wolf->posx -= mystruct->wolf->dirx * mystruct->movespeed;
		if (mystruct->worldmap[(int)(mystruct->wolf->posx)]
				[(int)(mystruct->wolf->posy - mystruct->wolf->diry
					* mystruct->movespeed)] == 0)
			mystruct->wolf->posy -= mystruct->wolf->diry * mystruct->movespeed;
	}
}
