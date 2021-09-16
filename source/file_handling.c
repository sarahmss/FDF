/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_handling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 20:45:09 by smodesto          #+#    #+#             */
/*   Updated: 2021/09/15 20:52:01 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/*
** Allocate memory for hex->color and z->matrix
*/
static void	alloc(t_fdf *mlx)
{
	int	i;

	i = 0;
	mlx->z_matrix = (int **) malloc(sizeof(int *) * (mlx->height));
	mlx->hex_color = (int **)malloc(sizeof(int *) * (mlx->height));
	if (!(mlx->z_matrix) || !(mlx->hex_color))
		check_error(1, "ALLOC ERROR");
	i = 0;
	while (i < mlx->height)
	{
		mlx->z_matrix[i] = (int *)malloc(sizeof(int) * (mlx->width));
		mlx->hex_color[i] = (int *)malloc(sizeof(int) * (mlx->width));
		if (!(mlx->z_matrix[i]) || !(mlx->hex_color[i]))
			check_error(1, "ALLOC ERROR");
		i++;
	}
}

/*
** get_heght_width function usesgnl to read each line of a
** file and then storage the amount of rows and columns
** with the help of ft_split
*/
static void	get_height_width(char *filename, t_fdf *mlx)
{
	int		fd;
	char	*line;
	char	**split_x;

	mlx->height = 0;
	mlx->width = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		check_error(fd, "Unable to open file.");
	while (get_next_line(fd, &line))
	{
		if (mlx->height == 0)
		{
			split_x = ft_split(line, ' ');
			while (split_x[mlx->width])
				free(split_x[mlx->width++]);
			free(split_x);
		}
		mlx->height++;
		ft_free_g(&line);
	}
	ft_free_g(&line);
	close(fd);
}

/*
** put z values into a matrix
** if the point comes with color save it in a matrix
*/
static void	fill_matrix(int *z_line, char *line, int *color)
{
	int		i;
	char	**num;
	char	*hex;

	i = 0;
	num = ft_split(line, ' ');
	while (num[i])
	{
		z_line[i] = ft_atoi(num[i]);
		hex = ft_strchr(num[i], 'x');
		if (hex)
			color[i] = ft_atoi_base(++hex, 16);
		else
			color[i] = 0;
		free(num[i]);
		i++;
	}
	free(num);
}

void	read_file(char *filename, t_fdf *mlx)
{
	int		i;
	char	*line;
	int		fd;

	i = 0;
	get_height_width(filename, mlx);
	alloc(mlx);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		check_error(fd, "Unable to open mlx.");
	while (get_next_line(fd, &line))
	{
		fill_matrix(mlx->z_matrix[i], line, mlx->hex_color[i]);
		ft_free_g(&line);
		i++;
	}
	ft_free_g(&line);
	close(fd);
}
