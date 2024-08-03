/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yususato <yususato@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 19:28:40 by hmiyazak          #+#    #+#             */
/*   Updated: 2024/08/03 19:14:37 by yususato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

typedef struct s_data {
    void    *mlx;
    void    *win;
    void    *img;
    char    *addr;
    int     bits;
    int     line;
    int     endian;
    int     img_width;
    int     img_height;
} t_data;

void    my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->line + x * (data->bits / 8));
    *(unsigned int *)dst = color;
}

int key_press(int keycode, t_data *data)
{
    if (keycode == 126)
        printf("Up\n");
    else if (keycode == 125)
        printf("Down\n");
    mlx_clear_window(data->mlx, data->win);
    mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
    return (0);
}

void	ray_cast(t_data *data)
{
	
}

int main(void)
{
    t_data  data;
    int     x;
    int     y;
    int     color1;
    int     color2;

    x = 0;
    y = 0;
    color1 = 0x0000FF;
    color2 = 0x000000;
    data.mlx = mlx_init();
    data.win = mlx_new_window(data.mlx, 800,600,"cub3D");
    data.img = mlx_new_image(data.mlx, 800, 600);
    data.addr = mlx_get_data_addr(data.img, &data.bits, &data.line, &data.endian);
	ray_cast(data);
    mlx_put_image_to_window(data.mlx, data.win, data.img, 0, 0);
    mlx_key_hook(data.win, key_press, &data);
    mlx_loop(data.mlx);
}
