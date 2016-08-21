/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_img.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avella <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 16:55:23 by avella            #+#    #+#             */
/*   Updated: 2016/03/14 16:56:13 by avella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	my_pixel_put_to_image(t_img *myimg, int x, int y, int color)
{
	myimg->data = mlx_get_data_addr(myimg->img_ptr,
			&myimg->bpp, &myimg->sizeline, &myimg->endian);
	myimg->data[y * myimg->sizeline + x * myimg->bpp / 8] = color % 256;
	color /= 256;
	myimg->data[y * myimg->sizeline + x * myimg->bpp / 8 + 1] = color % 256;
	color /= 256;
	myimg->data[y * myimg->sizeline + x * myimg->bpp / 8 + 2] = color % 256;
}
