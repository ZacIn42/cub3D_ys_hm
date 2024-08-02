/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yususato <yususato@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 16:17:29 by yususato          #+#    #+#             */
/*   Updated: 2024/08/02 17:56:01 by yususato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>

#define WIDTH 800
#define HEIGHT 600
#define RECT_SIZE 80

typedef struct {
    void *mlx;
    void *win;
    void *img;
    char *img_data;
    int bits_per_pixel;
    int line_length;
    int endian;
    int rect_x;
    int rect_y;
} t_data;

void draw_rectangle(t_data *data, int x, int y, int size, int color) {
    int i, j;

    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            int pixel = (y + i) * data->line_length + (x + j) * (data->bits_per_pixel / 8);
            data->img_data[pixel] = color;
            data->img_data[pixel + 1] = color >> 8;
            data->img_data[pixel + 2] = color >> 16;
        }
    }
}

int key_press(int keycode, t_data *data) {
    if (keycode == 65307) // Esc key to exit
        exit(0);
    if (keycode == 65361) // Left arrow
        data->rect_x -= 10;
    if (keycode == 65362) // Up arrow
        data->rect_y -= 10;
    if (keycode == 65363) // Right arrow
        data->rect_x += 10;
    if (keycode == 65364) // Down arrow
        data->rect_y += 10;

    mlx_clear_window(data->mlx, data->win);
    draw_rectangle(data, data->rect_x, data->rect_y, RECT_SIZE, 0xFF0000);
    mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
    return 0;
}

int main() {
    t_data data;

    data.mlx = mlx_init();
    data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "MiniLibX Sample");
    data.img = mlx_new_image(data.mlx, WIDTH, HEIGHT);
    data.img_data = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_length, &data.endian);

    data.rect_x = WIDTH / 2 - RECT_SIZE / 2;
    data.rect_y = HEIGHT / 2 - RECT_SIZE / 2;

    draw_rectangle(&data, data.rect_x, data.rect_y, RECT_SIZE, 0x00FF00);
    mlx_put_image_to_window(data.mlx, data.win, data.img, 0, 0);

    mlx_key_hook(data.win, key_press, &data);
    mlx_loop(data.mlx);

    return 0;
}