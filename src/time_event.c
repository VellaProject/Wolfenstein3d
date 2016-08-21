/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_event.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avella <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 17:23:29 by avella            #+#    #+#             */
/*   Updated: 2016/03/15 14:32:43 by avella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	yay_norme(t_struct *mystruct, int first)
{
	mystruct->worldmap[3][first - 1] = 0;
	mystruct->worldmap[3][first] = 2;
	if (mystruct->wolf->posx >= 3 && mystruct->wolf->posx <= 5 &&
			mystruct->wolf->posy >= first - 1 &&
			mystruct->wolf->posy <= first + 1)
	{
		mystruct->wolf->posx = 11;
		mystruct->wolf->posy = 10;
	}
}

void	my_animes(t_struct *mystruct)
{
	static int count;
	static int first;

	if (!first)
		first = 5;
	if (!count)
		count = 0;
	if (mystruct->eetat == 1 && mystruct->gotetat == 1)
		mystruct->valuev = 5;
	else if (mystruct->eetat == 0)
		mystruct->valuev = 1;
	count++;
	if (count >= mystruct->valuev)
	{
		yay_norme(mystruct, first);
		if (first < 24)
			first++;
		else
			first = 5;
		count = 0;
	}
}

void	my_shift(t_struct *mystruct)
{
	if (mystruct->shiftetat == 1)
	{
		mystruct->movespeed = 0.4;
		mystruct->rotspeed = 0.2;
	}
	else if (mystruct->shiftetat == 0)
	{
		mystruct->movespeed = 0.1;
		mystruct->rotspeed = 0.05;
	}
}

void	my_q(t_struct *mystruct)
{
	if (mystruct->qetat == 1)
	{
		if (mystruct->wolf->posx >= 15 && mystruct->wolf->posx <= 16 &&
				mystruct->wolf->posy >= 21 && mystruct->wolf->posy <= 22.5)
		{
			mystruct->worldmap[15][22] = 0;
			mystruct->gotetat = 1;
		}
		if (mystruct->wolf->posx >= 0.8 && mystruct->wolf->posx <= 1.5 &&
				mystruct->wolf->posy >= 10 && mystruct->wolf->posy <= 11)
		{
			ft_putstr("WAAAAAAAAAAAAAAAAAAW\n");
			exit(1);
		}
	}
}

int		the_move2(t_struct *mystruct)
{
	mystruct->movespeed = 0.1;
	mystruct->rotspeed = 0.05;
	my_animes(mystruct);
	my_shift(mystruct);
	my_left_right(mystruct);
	my_up_down(mystruct);
	my_q(mystruct);
	mlx_destroy_image(mystruct->mlx, mystruct->img->img_ptr);
	mystruct->img->img_ptr = mlx_new_image(mystruct->mlx, WIDTH, HEIGHT);
	draw2(mystruct);
	if (mystruct->gotetat == 1)
		gotet(mystruct);
	mlx_put_image_to_window(mystruct->mlx, mystruct->win,
			mystruct->img->img_ptr, 0, 0);
	return (0);
}
