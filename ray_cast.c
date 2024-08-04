#include <mlx.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

#define WIN_WIDTH 640
#define WIN_HEIGHT 480
#define MAP_WIDTH 24
#define MAP_HEIGHT 24
#define TEX_WIDTH 64
#define TEX_HEIGHT 64

typedef struct  s_mlx {
    void        *mlx;
    void        *win;
    void        *img;
    int         *data;
    int         bpp;
    int         size_l;
    int         endian;
}               t_mlx;

typedef struct  s_player {
    double      posX;
    double      posY;
    double      dirX;
    double      dirY;
    double      planeX;
    double      planeY;
}               t_player;

int worldMap[MAP_WIDTH][MAP_HEIGHT] = {
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

void    raycasting(t_mlx *mlx, t_player *player)
{
    for (int x = 0; x < WIN_WIDTH; x++)
    {
        // カメラプレーン内のX座標を計算
        double cameraX = 2 * x / (double)WIN_WIDTH - 1;
        double rayDirX = player->dirX + player->planeX * cameraX;
        double rayDirY = player->dirY + player->planeY * cameraX;

        // 現在のマップ位置
        int mapX = (int)player->posX;
        int mapY = (int)player->posY;

        // 距離を測定するための変数
        double sideDistX;
        double sideDistY;

        // 一つのXまたはY方向に進む距離
        double deltaDistX = fabs(1 / rayDirX);
        double deltaDistY = fabs(1 / rayDirY);
        double perpWallDist;

        // ステップの方向と初期サイドディスタンス
        int stepX;
        int stepY;

        int hit = 0; // 壁にぶつかったか
        int side; // XかYか

        if (rayDirX < 0)
        {
            stepX = -1;
            sideDistX = (player->posX - mapX) * deltaDistX;
        }
        else
        {
            stepX = 1;
            sideDistX = (mapX + 1.0 - player->posX) * deltaDistX;
        }
        if (rayDirY < 0)
        {
            stepY = -1;
            sideDistY = (player->posY - mapY) * deltaDistY;
        }
        else
        {
            stepY = 1;
            sideDistY = (mapY + 1.0 - player->posY) * deltaDistY;
        }

        // DDAアルゴリズムを使って壁にぶつかるまで進む
        while (hit == 0)
        {
            if (sideDistX < sideDistY)
            {
                sideDistX += deltaDistX;
                mapX += stepX;
                side = 0;
            }
            else
            {
                sideDistY += deltaDistY;
                mapY += stepY;
                side = 1;
            }
            if (worldMap[mapX][mapY] > 0) hit = 1;
        }

        // 壁までの垂直距離を計算
        if (side == 0) perpWallDist = (mapX - player->posX + (1 - stepX) / 2) / rayDirX;
        else perpWallDist = (mapY - player->posY + (1 - stepY) / 2) / rayDirY;

        // 壁の高さを計算
        int lineHeight = (int)(WIN_HEIGHT / perpWallDist);

        // 描画開始と終了位置を計算
        int drawStart = -lineHeight / 2 + WIN_HEIGHT / 2;
        if (drawStart < 0) drawStart = 0;
        int drawEnd = lineHeight / 2 + WIN_HEIGHT / 2;
        if (drawEnd >= WIN_HEIGHT) drawEnd = WIN_HEIGHT - 1;

        // 壁の色を決定
        int color;
        if (side == 1) color = 0xAA0000; // Y方向の壁
        else color = 0x00AA00; // X方向の壁

        // 垂直線を描画
        for (int y = drawStart; y < drawEnd; y++)
        {
            mlx->data[y * WIN_WIDTH + x] = color;
        }
    }
    // イメージをウィンドウに表示
    mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
}

int main()
{
    t_mlx mlx;
    t_player player;

    // MiniLibXの初期化
    mlx.mlx = mlx_init();
    mlx.win = mlx_new_window(mlx.mlx, WIN_WIDTH, WIN_HEIGHT, "Raycasting");
    mlx.img = mlx_new_image(mlx.mlx, WIN_WIDTH, WIN_HEIGHT);
    mlx.data = (int *)mlx_get_data_addr(mlx.img, &mlx.bpp, &mlx.size_l, &mlx.endian);

    // プレイヤーの初期位置と方向
    player.posX = 22.0;
    player.posY = 12.0;
    player.dirX = -1.0;
    player.dirY = 0.0;
    player.planeX = 0.0;
    player.planeY = 10;

    // メインループ
    while (1)
    {
        // レイキャスティングでシーンを描画
        raycasting(&mlx, &player);

        // イベントループ
        mlx_loop(mlx.mlx);
    }
    return 0;
}