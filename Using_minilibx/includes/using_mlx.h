/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   using_mlx.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 18:56:26 by smodesto          #+#    #+#             */
/*   Updated: 2021/08/17 19:26:05 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef USING_MLX_H
#define USING_MLX_H

#define KEY_ESC			65307
# define KEY_Q			113
# define KEY_W			119
# define KEY_E			101
# define KEY_R			114
# define KEY_A			97
# define KEY_S			115
# define KEY_D			100

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../libraries/minilibx-linux/mlx.h"
#include "../libraries/libft/libft.h"

typedef struct s_data
{
	double	deltaX;
	double	deltaY;
	int		pixels;
	double	pixelX;
	double	pixelY;
}			t_data;

typedef struct s_program
{
	void	*mlx_ptr;
	void	*win_ptr;
}			t_program;

int	using_mlx1(void);

int	using_mlx2(void);

int	using_mlx2_1(void);

int	using_mlx2_2(void);

int	using_mlx3(void);

int	using_mlx4(void);

int	using_mlx5(void);

int	using_mlx6(void);

int draw_line(void *mlx, void *win, int beginX, int beginY, int endX, int endY, int color);

#endif

