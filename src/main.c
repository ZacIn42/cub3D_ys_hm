/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyazak <hmiyazak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 19:28:40 by hmiyazak          #+#    #+#             */
/*   Updated: 2024/08/24 20:26:19 by hmiyazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int	init_cub(t_cub *cub, t_field *field);
// static int	init_img(void *mlx, t_img *img, char *file_path);
// static int	init_textures(void *mlx, t_field *field);

int	main(int argc, char **argv)
{
	t_field		field;
	t_cub		cub;

	if (argc != 2)
		put_error_exit("ERROR: 1 argument required: filename, *.cub\n");
	parse_file(&field);
	init_cub(&cub, &field);
	set_mlx_hooks(&cub);
	draw_wall(&cub, &field);
	mlx_loop(cub.mlx);
	exit(0);
}

static int	init_cub(t_cub *cub, t_field *field)
{
	cub->mlx = mlx_init();
	if (cub->mlx == NULL)
		put_error_exit("ERROR: failed to init mlx\n");
	cub->window = mlx_new_window(cub->mlx, WIN_WIDTH, WIN_HEIGHT, "cub3D");
	if (cub->window == NULL)
		put_error_exit("ERROR: failed to create a new window\n");
	cub->img.img = mlx_new_image(cub->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (cub->img.img == NULL)
	{
		mlx_destroy_window(cub->mlx, cub->window);
		put_error_exit("ERROR: failed to create a new image\n");
	}
	cub->img.width = WIN_WIDTH;
	cub->img.height = WIN_HEIGHT;
	cub->img.addr = mlx_get_data_addr(cub->img.img, \
		&cub->img.b_p_pixel, &cub->img.line_len, &cub->img.endian);
	if (cub->img.addr == NULL)
	{
		mlx_destroy_window(cub->mlx, cub->window);
		mlx_destroy_image(cub->mlx, cub->img.img);
		put_error_exit("ERROR: failed to get image address\n");
	}
	cub->field = field;
	return (0);
}

// static int	init_textures(void *mlx, t_field *fld)
// {
// 	if (init_img(mlx, &fld->textures[NORTH], fld->texture_paths[NORTH]) != 0)
// 		return (1);
// 	if (init_img(mlx, &fld->textures[EAST], fld->texture_paths[EAST]) != 0)
// 		return (1);
// 	if (init_img(mlx, &fld->textures[SOUTH], fld->texture_paths[SOUTH]) != 0)
// 		return (1);
// 	if (init_img(mlx, &fld->textures[WEST], fld->texture_paths[WEST]) != 0)
// 		return (1);
// 	return (0);
// }

// static int	init_img(void *mlx, t_img *img, char *file_path)
// {
// 	img->img = mlx_xpm_file_to_image(mlx, file_path, &img->width, &img->height);
// 	img->addr = mlx_get_data_addr(img->img, &img->b_p_pixel, \
// 									&img->line_len, &img->endian);
// 	return (0);
// }
