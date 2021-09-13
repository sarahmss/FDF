/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 18:56:26 by smodesto          #+#    #+#             */
/*   Updated: 2021/09/13 11:12:47 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include "../libraries/minilibx-linux/mlx.h"
# include "../libraries/libft/libft.h"
# include "./structs.h"
# include "./keymap.h"

// events
void		check_error(int err, char *msg);
void		control_events(t_fdf *mlx);
// draw
void		draw(t_fdf *mlx, t_image *img);
// img
void		ft_create_image(t_fdf *mlx, t_image *img);
void		my_mlx_pixel_put(t_fdf *mlx, int x, int y, t_image *img);
//	File Handling
void		read_file(char *file_name, t_fdf *data);
// Menu
void		print_menu(t_fdf *fdf);
// init
t_fdf		*init_fdf(void);
t_image		*init_img(t_fdf *mlx);
t_camera	*init_camera(t_fdf *mlx);
// controls
void		zoom(int key, t_fdf *mlx);
void		move(int key, t_fdf *mlx);
void		rotate(int key, t_fdf *mlx);
void		change_color(int key, t_fdf *mlx);

#endif
