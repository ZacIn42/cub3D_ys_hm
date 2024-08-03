#include "cub.h"

int main(void)
{
    void    *mlx_ptr;
    void    *win_ptr;

    // MiniLibX の初期化
    mlx_ptr = mlx_init();
    if (mlx_ptr == NULL)
        return (1);

    // ウィンドウの作成 (幅: 800, 高さ: 600)
    win_ptr = mlx_new_window(mlx_ptr, 800, 600, "Clear Window Example");
    if (win_ptr == NULL)
    {
        mlx_destroy_display(mlx_ptr);
        free(mlx_ptr);
        return (1);
    }

    // 四角形を描画
    int x_start = 100;
    int y_start = 100;
    int width = 200;
    int height = 150;
    int color = 0x00FF00;  // 緑色

    for (int x = x_start; x < x_start + width; x++)
    {
        for (int y = y_start; y < y_start + height; y++)
        {
            mlx_pixel_put(mlx_ptr, win_ptr, x, y, color);
        }
    }

    // 少し待機 (ユーザーが四角形を確認できるように)
    sleep(3);

    // ウィンドウをクリア
    mlx_clear_window(mlx_ptr, win_ptr);

    // イベントループを開始
    mlx_loop(mlx_ptr);

    return (0);
}