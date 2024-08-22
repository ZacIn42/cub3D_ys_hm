/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyazak <hmiyazak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 19:28:40 by hmiyazak          #+#    #+#             */
/*   Updated: 2024/08/23 07:55:34 by hmiyazak         ###   ########.fr       */
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
	draw_wall(&cub, &field);
	mlx_loop(cub.mlx);
	return (0);
}

static int	parse_file(t_field *field)
{
	static char	*map[5] = {
		"011111",
		"1N0101",
		"101001",
		"110001",
		"111111",
	};
	// static char	*map[14] = {
	// 	"        1111111111111111111111111",
	// 	"        1000000000110000000000001",
	// 	"        1011000001110000000000001",
	// 	"        1001000000000000000000001",
	// 	"111111111011000001110000000000001",
	// 	"100000000011000001110111111111111",
	// 	"11110111111111011100000010001",
	// 	"11110111111111011101010010001",
	// 	"11000000110101011100000010001",
	// 	"10000000000000001100000010001",
	// 	"10000000000000001101010010001",
	// 	"11000001110101011111011110N01aaa11",
	// 	"11110111 1110101 101111010001",
	// 	"11111111 1111111 111111111111",
	// };

	field->map = &map[0];
	// vec_init(&field->user.pos, 9.5, 0.5);
	vec_init(&field->user.pos, 0.5, 0.5);
	field->user.dir = NORTH;
	strcpy(field->texture_paths[NORTH], "./images/tile.xpm");
	strcpy(field->texture_paths[EAST], "./images/yellowbucks.xpm");
	strcpy(field->texture_paths[SOUTH], "./images/shingle.xpm");
	strcpy(field->texture_paths[WEST], "./images/wood2.xpm");
	field->c_color = 0xFFFFFF;
	field->f_color = 0x000000;
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
		&cub->img.b_p_pixel, &cub->img.line_len, &cub->img.endian);
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
	img->addr = mlx_get_data_addr(img->img, &img->b_p_pixel, \
									&img->line_len, &img->endian);
	return (0);
}
