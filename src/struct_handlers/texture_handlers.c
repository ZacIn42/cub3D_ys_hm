/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyazak <hmiyazak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 10:00:01 by hmiyazak          #+#    #+#             */
/*   Updated: 2024/08/30 10:21:00 by hmiyazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int	init_img(void *mlx, t_img *img, char *file_path);

int	init_textures(void *mlx, t_field *fld)
{
	if (init_img(mlx, &fld->textures[NORTH], fld->texture_paths[NORTH]) != 0)
		return (1);
	if (init_img(mlx, &fld->textures[EAST], fld->texture_paths[EAST]) != 0)
		return (1);
	if (init_img(mlx, &fld->textures[SOUTH], fld->texture_paths[SOUTH]) != 0)
		return (1);
	if (init_img(mlx, &fld->textures[WEST], fld->texture_paths[WEST]) != 0)
		return (1);
	return (0);
}

void	destroy_textures(void *mlx, t_field *field)
{
	mlx_destroy_image(mlx, field->textures[NORTH].img);
	mlx_destroy_image(mlx, field->textures[EAST].img);
	mlx_destroy_image(mlx, field->textures[SOUTH].img);
	mlx_destroy_image(mlx, field->textures[WEST].img);
}

static int	init_img(void *mlx, t_img *img, char *file_path)
{
	img->img = mlx_xpm_file_to_image(mlx, file_path, &img->width, &img->height);
	if (img->img == NULL)
		return (perror_return_one("failed to create image from .xpm file\n"));
	img->addr = mlx_get_data_addr(img->img, &img->b_p_pixel, \
									&img->line_len, &img->endian);
	if (img->img == NULL)
		return (perror_return_one("failed to get data address of .xpm file\n"));
	return (0);
}
