/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 08:51:24 by smodesto          #+#    #+#             */
/*   Updated: 2021/09/15 20:59:30 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# define WIN_WIDTH		1280
# define WIN_HEIGHT		600
# define MENU_WIDTH		200

# define WIN_CENTER_X	400
# define WIN_CENTER_Y	300

//Colors
# define RED				0XFF2222
# define GREEN				0X22FF22
# define BLUE				0X2222FF
# define PURPLE				0XFF22FF
# define WHITE				0XFFFFFF
# define GREY				0XAAAAAA
# define DGREY				0X444444
# define BACKGROUND			0X222222
# define MENU_BACKGROUND	1973790
# define TEXT_COLOR			0XEAEAEA

typedef struct s_camera
{
	int		zoom;
	double	alpha;
	double	beta;
	double	gamma;
	float	z_divisor;
	int		x_offset;
	int		y_offset;
}				t_camera;

typedef struct s_image
{
	int			*img;
	char		*data_address;
	int			bpp;
	int			line_size;
	int			endian;
	int			width;
	int			height;
	t_camera	*camera;
}				t_image;

typedef struct s_vector
{
	float	x0;
	float	y0;
	float	x1;
	float	y1;
	int		z0;
	int		z1;
	int		max;
	float	delta_x;
	float	delta_y;
	int		color;
}				t_vector;

typedef struct s_control_colors
{
	int		c4;
	int		c5;
	int		c6;
	int		c7;
}				t_cc;

typedef struct s_fdf
{
	void		*mlx;
	void		*win;
	int			**z_matrix;
	int			**hex_color;
	int			width;
	int			height;
	t_vector	*temp_vector;
	t_image		*img;
	t_cc		*colors;
}				t_fdf;

#endif
