/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avella <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 16:10:58 by avella            #+#    #+#             */
/*   Updated: 2016/03/15 16:16:47 by avella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H
# include <mlx.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"
# include "get_next_line.h"
# include <math.h>
# define WIDTH 900
# define HEIGHT 900
# define MAPWIDTH 29
# define MAPHEIGHT 24

typedef struct										s_wolf
{
	double camerax;
	double rayposx;
	double rayposy;
	double raydirx;
	double raydiry;
	double posx;
	double posy;
	double dirx;
	double diry;
	double planex;
	double planey;
	double time;
	double oldtime;

}													t_wolf;

typedef struct										s_inwolf
{
	double	posx;
	double	posy;
	double	dirx;
	double	diry;
	double	planex;
	double	planey;
	double	time;
	double	oldtime;
	double	camerax;
	double	rayposx;
	double	rayposy;
	double	raydirx;
	double	raydiry;
	int		mapx;
	int		mapy;
	double	sidedistx;
	double	sidedisty;
	double	deltadistx;
	double	deltadisty;
	double	perpwalldist;
	int		stepx;
	int		stepy;
	int		hit;
	int		side;
	int		lineheight;
	int		drawstart;
	int		drawend;
	int		color;
	int		x;
}													t_inwolf;

typedef struct										s_img
{
	void				*mlx;
	void				*win;
	unsigned long		img_color;
	char				*data;
	void				*img_ptr;
	int					sizeline;
	int					bpp;
	int					x;
	int					y;
	int					endian;
	void				*mlx_ptr;
}													t_img;

typedef struct										s_line
{
	int dx;
	int dy;
	int i;
	int xinc;
	int yinc;
	int cumul;
	int x;
	int y;
}													t_line;

typedef struct										s_temp
{
	int x1;
	int x2;
	int y1;
	int y2;
	int val1;
	int val2;
	int color;
}													t_temp;

typedef struct										s_struct
{
	int		qetat;
	int		eetat;
	int		shiftetat;
	int		rightetat;
	int		leftetat;
	int		upetat;
	int		downetat;
	int		gotetat;
	int		valuev;
	void	*mlx;
	void	*win;
	t_img	*img;
	t_wolf	*wolf;
	int		worldmap[MAPWIDTH][MAPHEIGHT];
	int		i;
	int		j;
	int		i2;
	double	movespeed;
	double	rotspeed;
}													t_struct;

void												give_map_to_struct(char
													*line, t_struct *mystruct);
int													my_expose(t_struct
													*mystruct);
char												*my_maps(void);
char												*ft_strjoins(char const *s1,
													char const *s2);
void												what_a_pro_draw(t_temp
													*coord, t_struct *mystruct
													, int color);
t_temp												*give_temp(int x1, int y1,
													int x2, int y2);
void												draw_line_on_img(t_img
													*myimg,
													t_temp *temp, int color);
void												draw2(t_struct *mystruct);
void												my_animes(t_struct
													*mystruct);
int													the_move2(t_struct
													*mystruct);
void												gotet(t_struct *mystruct);
void												yo_right(t_struct
													*mystruct);
void												my_up_down(t_struct
													*mystruct);
void												my_left_right(t_struct
													*mystruct);
void												w_early_give(t_inwolf *w,
													t_struct *mystruct);
void												w_inwhile_give(t_inwolf *w);
void												use_dir(t_inwolf *w);
t_struct											*give_struct(void);
void												my_pixel_put_to_image(t_img
													*myimg,
													int x, int y, int color);
#endif
