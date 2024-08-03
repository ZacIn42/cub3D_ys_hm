/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyazak <hmiyazak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 19:28:40 by hmiyazak          #+#    #+#             */
/*   Updated: 2024/08/03 18:31:46 by hmiyazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int	parse_file(t_field *field);
static int	init_cub(t_cub *cub, t_field *field);
static int	init_img(void *mlx, t_img *img, char *file_path);
static int	init_textures(void *mlx, t_field *field);

int	main(void)
{
	t_field		field;
	t_cub		cub;

	if (parse_file(&field) != 0)
		exit(1);
	if (init_cub(&cub, &field) != 0)
		exit(1);
	if (init_textures(cub.mlx, &field) != 0)
		exit(1);
	set_mlx_hooks(&cub);
	// // draw_wall(&mlx, &user, &(wall.start), &(wall.end));
	mlx_loop(cub.mlx);
	return (0);
}

static int	parse_file(t_field *field)
{
	static char	*map[5] = {
		"111111",
		"100101",
		"101001",
		"1100N1",
		"111111",
	};

	field->map = &map[0];
	vec_init(&field->user.pos, 4.5, 3.5);
	field->user.dir = NORTH;
	strcpy(field->texture_paths[NORTH], "./images/tile.xpm");
	strcpy(field->texture_paths[EAST], "./images/tile.xpm");
	strcpy(field->texture_paths[SOUTH], "./images/tile.xpm");
	strcpy(field->texture_paths[WEST], "./images/tile.xpm");
	field->c_color = 0xFF0000;
	field->f_color = 0x00FF00;
	return (0);
}

static int	init_cub(t_cub *cub, t_field *field)
{
	cub->mlx = mlx_init();
	cub->window = mlx_new_window(cub->mlx, WIN_WIDTH, WIN_HEIGHT, "cub3D");
	cub->img.img = mlx_new_image(cub->mlx, WIN_WIDTH, WIN_HEIGHT);
	cub->img.width = WIN_WIDTH;
	cub->img.height = WIN_HEIGHT;
	cub->img.addr = mlx_get_data_addr(cub->img.img, \
		&cub->img.bits_per_pixel, &cub->img.line_length, &cub->img.endian);
	cub->field = field;
	return (0);
}

static int	init_textures(void *mlx, t_field *fld)
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

static int	init_img(void *mlx, t_img *img, char *file_path)
{
	img->img = mlx_xpm_file_to_image(mlx, file_path, &img->width, &img->height);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, \
									&img->line_length, &img->endian);
	return (0);
}
