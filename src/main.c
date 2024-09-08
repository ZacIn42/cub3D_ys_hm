/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yususato <yususato@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 09:05:11 by hmiyazak          #+#    #+#             */
/*   Updated: 2024/09/08 14:18:57 by yususato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static bool	check_file(char *filename);
static int	init_cub(t_cub *cub, t_field *field);

int	main(int argc, char *argv[])
{
	t_field		field;
	t_cub		cub;

	if (argc != 2 || check_file(argv[1]) == false)
		exit(perror_return_one("argument should be a readable file, *.cub\n"));
	if (init_cub(&cub, &field) != 0)
		exit(1);
	if (parse_file(&cub, argv[1]) != 0)
	{
		mlx_destroy_image(cub.mlx, cub.img.img);
		mlx_destroy_window(cub.mlx, cub.window);
		exit(1);
	}
	if (draw_scene(&cub, &field) != 0)
	{
		free_str_array(field.map);
		destroy_textures(cub.mlx, &field);
		mlx_destroy_image(cub.mlx, cub.img.img);
		mlx_destroy_window(cub.mlx, cub.window);
		exit(1);
	}
	set_mlx_hooks(&cub);
	mlx_loop(cub.mlx);
	exit(0);
}

static bool	check_file(char *filename)
{
	char	*extension;
	int		fd;

	extension = ft_strrchr(filename, '.');
	if (extension == NULL)
		return (false);
	if (ft_strncmp(extension, ".cub\0", 5) != 0)
		return (false);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		perror(filename);
		return (false);
	}
	else if (close(fd) != 0)
	{
		perror(filename);
		return (false);
	}
	return (true);
}

static int	init_cub(t_cub *cub, t_field *field)
{
	cub->mlx = mlx_init();
	if (cub->mlx == NULL)
		return (perror_return_one("failed to init mlx\n"));
	cub->window = mlx_new_window(cub->mlx, WIN_WIDTH, WIN_HEIGHT, "cub3D");
	if (cub->window == NULL)
		return (perror_return_one("failed to create a new window\n"));
	cub->img.img = mlx_new_image(cub->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (cub->img.img == NULL)
	{
		mlx_destroy_window(cub->mlx, cub->window);
		return (perror_return_one("failed to create a new image\n"));
	}
	cub->img.width = WIN_WIDTH;
	cub->img.height = WIN_HEIGHT;
	cub->img.addr = mlx_get_data_addr(cub->img.img, \
		&cub->img.bpp, &cub->img.line_len, &cub->img.endian);
	if (cub->img.addr == NULL)
	{
		mlx_destroy_window(cub->mlx, cub->window);
		mlx_destroy_image(cub->mlx, cub->img.img);
		return (perror_return_one("failed to get image address\n"));
	}
	cub->field = field;
	return (0);
}
