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
    while (y < 600)
    {
        while (x < 800)
        {
            if (y <= 300)
                my_mlx_pixel_put(&data, x, y, color2);
            else
                my_mlx_pixel_put(&data, x, y, color1);
            x++;
        }
        x = 0;
        y++;
    }
    mlx_put_image_to_window(data.mlx, data.win, data.img, 0, 0);
    mlx_key_hook(data.win, key_press, &data);
    mlx_loop(data.mlx);
}
