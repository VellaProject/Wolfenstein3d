/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_give.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avella <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 16:17:38 by avella            #+#    #+#             */
/*   Updated: 2016/03/02 16:22:51 by avella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		hello_norme(t_struct *mystruct)
{
	mystruct->upetat = 0;
	mystruct->downetat = 0;
	mystruct->leftetat = 0;
	mystruct->rightetat = 0;
	mystruct->shiftetat = 0;
	mystruct->eetat = 0;
	mystruct->qetat = 0;
	mystruct->gotetat = 0;
	mystruct->valuev = 1;
	mystruct->i = 0;
	mystruct->j = 0;
	mystruct->i2 = 0;
}

t_struct	*give_struct(void)
{
	t_struct		*mystruct;
	t_img			*myimg;
	t_wolf			*wo;

	wo = (t_wolf *)malloc(sizeof(t_wolf));
	myimg = (t_img *)malloc(sizeof(t_img));
	mystruct = (t_struct *)malloc(sizeof(t_struct) * 1);
	mystruct->mlx = mlx_init();
	mystruct->win = mlx_new_window(mystruct->mlx, WIDTH, HEIGHT, "WOLF");
	myimg->img_ptr = mlx_new_image(mystruct->mlx, WIDTH, HEIGHT);
	mystruct->img = myimg;
	mystruct->wolf = wo;
	mystruct->wolf->posx = 27;
	mystruct->wolf->posy = 10.5;
	mystruct->wolf->dirx = -1;
	mystruct->wolf->diry = 0;
	mystruct->wolf->planex = 0;
	mystruct->wolf->planey = 0.66;
	hello_norme(mystruct);
	return (mystruct);
}
