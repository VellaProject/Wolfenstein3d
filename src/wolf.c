/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avella <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 15:06:43 by avella            #+#    #+#             */
/*   Updated: 2016/03/15 15:12:30 by avella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		event_mlx(int keycode, t_struct *mystruct)
{
	if (keycode == 53)
		exit(1);
	if (keycode == 14)
		mystruct->eetat = 1;
	if (keycode == 12)
		mystruct->qetat = 1;
	if (keycode == 257)
		mystruct->shiftetat = 1;
	if (keycode == 126)
		mystruct->upetat = 1;
	if (keycode == 124)
		mystruct->rightetat = 1;
	if (keycode == 123)
		mystruct->leftetat = 1;
	if (keycode == 125)
		mystruct->downetat = 1;
	return (0);
}

int		event_release(int keycode, t_struct *mystruct)
{
	if (keycode == 14)
		mystruct->eetat = 0;
	if (keycode == 12)
		mystruct->qetat = 0;
	if (keycode == 257)
		mystruct->shiftetat = 0;
	if (keycode == 126)
		mystruct->upetat = 0;
	if (keycode == 125)
		mystruct->downetat = 0;
	if (keycode == 123)
		mystruct->leftetat = 0;
	if (keycode == 124)
		mystruct->rightetat = 0;
	return (0);
}

char	*ft_join(char const *s1, char const *s2, int len1, int len2)
{
	char		*join;
	int			i;
	int			j;

	i = 0;
	j = 0;
	join = malloc(sizeof(char) * (len1 + len2) + 1);
	while (s1[i] != '\0')
	{
		join[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		join[i] = s2[j];
		i++;
		j++;
	}
	join[i] = '\0';
	return (join);
}

char	*ft_strjoins(char const *s1, char const *s2)
{
	int		len1;
	int		len2;
	char	*join;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	join = ft_join(s1, s2, len1, len2);
	return (join);
}

int		main(void)
{
	t_struct	*mystruct;
	char		*line;

	line = my_maps();
	mystruct = give_struct();
	give_map_to_struct(line, mystruct);
	mlx_key_hook(mystruct->win, event_release, mystruct);
	mlx_hook(mystruct->win, 2, (1L << 1), event_mlx, mystruct);
	mlx_expose_hook(mystruct->win, my_expose, mystruct);
	my_expose(mystruct);
	mlx_loop_hook(mystruct->mlx, the_move2, mystruct);
	mlx_loop(mystruct->mlx);
	return (0);
}
