# include <mlx.h>
# include <math.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>

// WASD`
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2

// KEYBOARD ESC
# define K_ESC 53

#define mapWidth 24
#define mapHeight 24
#define screenWidth 640
#define screenHeight 480

// EVENT KEY
#define X_EVENT_KEY_PRESS   2
#define X_EVENT_KEY_EXIT    17
#define texWidth 64
#define texHeight 64

// get_img_data_addr 함수에서 쓸 변수를 갖고 있는 구조체.
typedef struct    s_img
{
    void    *img;
    int        *data;

    int        size_l;
    int        bpp;
    int        endian;
    int     img_width;
    int     img_height;
}                t_img;

typedef struct    s_info
{
    double playerPositionX;
    double playerPositionY;
    double directionVectorX;
    double directionVectorY;
    double planeX;
    double planeY;
    void    *mlx;
    void    *win;
    double    moveSpeed;
    double    rotSpeed;

    t_img   img;
    int     buf[screenHeight][screenWidth];
    int     **texture;

}                t_info;

int calculateAndSaveToMap(t_info *info);
void imageDraw(t_info *info);

int worldMap[mapWidth][mapHeight] =
{
  {8,8,8,8,8,8,8,8,8,8,8,4,4,6,4,4,6,4,6,4,4,4,6,4},
  {8,0,0,0,0,0,0,0,0,0,8,4,0,0,0,0,0,0,0,0,0,0,0,4},
  {8,0,3,3,0,0,0,0,0,8,8,4,0,0,0,0,0,0,0,0,0,0,0,6},
  {8,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6},
  {8,0,3,3,0,0,0,0,0,8,8,4,0,0,0,0,0,0,0,0,0,0,0,4},
  {8,0,0,0,0,0,0,0,0,0,8,4,0,0,0,0,0,6,6,6,0,6,4,6},
  {8,8,8,8,0,8,8,8,8,8,8,4,4,4,4,4,4,6,0,0,0,0,0,6},
  {7,7,7,7,0,7,7,7,7,0,8,0,8,0,8,0,8,4,0,4,0,6,0,6},
  {7,7,0,0,0,0,0,0,7,8,0,8,0,8,0,8,8,6,0,0,0,0,0,6},
  {7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8,6,0,0,0,0,0,4},
  {7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8,6,0,6,0,6,0,6},
  {7,7,0,0,0,0,0,0,7,8,0,8,0,8,0,8,8,6,4,6,0,6,6,6},
  {7,7,7,7,0,7,7,7,7,8,8,4,0,6,8,4,8,3,3,3,0,3,3,3},
  {2,2,2,2,0,2,2,2,2,4,6,4,0,0,6,0,6,3,0,0,0,0,0,3},
  {2,2,0,0,0,0,0,2,2,4,0,0,0,0,0,0,4,3,0,0,0,0,0,3},
  {2,0,0,0,0,0,0,0,2,4,0,0,0,0,0,0,4,3,0,0,0,0,0,3},
  {1,0,0,0,0,0,0,0,1,4,4,4,4,4,6,0,6,3,3,0,0,0,3,3},
  {2,0,0,0,0,0,0,0,2,2,2,1,2,2,2,6,6,0,0,5,0,5,0,5},
  {2,2,0,0,0,0,0,2,2,2,0,0,0,2,2,0,5,0,5,0,0,0,5,5},
  {2,0,0,0,0,0,0,0,2,0,0,0,0,0,2,5,0,5,0,5,0,5,0,5},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5},
  {2,0,0,0,0,0,0,0,2,0,0,0,0,0,2,5,0,5,0,5,0,5,0,5},
  {2,2,0,0,0,0,0,2,2,2,0,0,0,2,2,0,5,0,5,0,0,0,5,5},
  {2,2,2,2,1,2,2,2,2,2,2,1,2,2,2,5,5,5,5,5,5,5,5,5}
};

int main_loop(t_info *info)
{
    calculateAndSaveToMap(info);
    imageDraw(info);

    return (0);
}

void imageDraw(t_info *info)
{
    for (int y = 0; y < screenHeight; y++)
        for (int x = 0; x < screenWidth; x++)
            info->img.data[y * screenWidth + x] = info->buf[y][x];

    mlx_put_image_to_window(info->mlx, info->win, info->img.img, 0, 0);
}

int calculateAndSaveToMap(t_info *info)
{
    int x;

        x = 0;
    while (x < screenWidth)
    {
        double cameraX = (2 * x / (double)(screenWidth)) - 1;
        printf("planeX: %f\n", info->planeX);
        printf("planeY: %f\n", info->planeY);
        printf("LOL: %f %f %f\n", info->directionVectorY, info->planeY, cameraX);
        double rayDirectionX = info->directionVectorX + info->planeX * cameraX;
        double rayDirectionY = info->directionVectorY + info->planeY * cameraX;
        int mapX = (int)(info->playerPositionX);
        int mapY = (int)(info->playerPositionY);
        double sideDistX;
        double sideDistY;
        double deltaDistX = fabs(1 / rayDirectionX);
        double deltaDistY = fabs(1 / rayDirectionY);
        double perpWallDist;
        int stepX;
        int stepY;
        int hit = 0;
        int side;
        printf("RayX: %f\n", deltaDistX);
		printf("RayY: %f\n", deltaDistY);
        printf("plater position: %f %f\n", info->playerPositionX, info->playerPositionY);
        if (rayDirectionX < 0)
        {
            stepX = -1;
            sideDistX = (info->playerPositionX - mapX) * deltaDistX;
        }
        else
        {
            stepX = 1;
            sideDistX = (mapX + 1.0 - info->playerPositionX) * deltaDistX;
        }
    	printf("rayDirection: %f\n", rayDirectionY);
        if (rayDirectionY < 0)
        {
            stepY = -1;
		    printf("yes\n");
            sideDistY = (info->playerPositionY - mapY) * deltaDistY;
        }
        else
        {
            stepY = 1;
		    printf("no\n");
            sideDistY = (mapY + 1.0 - info->playerPositionY) * deltaDistY;
        }

        printf("Side_sitX: %f\n", sideDistX);
		printf("Side_sitY: %f\n", sideDistY);
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
			printf("wall position: %d %d\n", mapX, mapY);
            if (worldMap[mapX][mapY] > 0)
                hit = 1;
        }

        int a = 0;
		while (a < 24)
		{
			int b = 0;
			while (b < 24)
			{
				if (a == mapX && b == mapY)
					printf("\033[0;31m%d\033[0m", worldMap[a][b]);
				else
					printf("%d", worldMap[a][b]);
				b++;
			}
			printf("\n");
			a++;
        }
        if (side == 0)
            perpWallDist = (mapX - info->playerPositionX + (1 - stepX) / 2) / rayDirectionX;
        else
            perpWallDist = (mapY - info->playerPositionY + (1 - stepY) / 2) / rayDirectionY;
        int lineHeight = (int)(screenHeight / perpWallDist);
        printf("distance: %d\n", lineHeight);
        int drawStart = (-lineHeight / 2) + (screenHeight / 2);
        if (drawStart < 0)
            drawStart = 0;
        int drawEnd = (lineHeight / 2) + (screenHeight / 2);
        if (drawEnd >= screenHeight)
            drawEnd = screenHeight - 1;
        int texNum = worldMap[mapX][mapY] - 1;
        double wallX;

        printf("WTFY: %d %d %f\n", mapY, stepY, rayDirectionY);
        if (side == 0)
            wallX = info->playerPositionY + perpWallDist * rayDirectionY;
        else
            wallX = info->playerPositionX + perpWallDist * rayDirectionX;
            
        wallX -= floor(wallX);
        int texX = (int)(wallX * (double)texWidth);
        if (side == 0 && rayDirectionX > 0)
            texX = texWidth - texX - 1;
        if (side == 1 && rayDirectionY < 0)
            texX = texWidth - texX - 1;
        double step = 1.0 * texHeight / lineHeight;
        double texPos = (drawStart - screenHeight / 2 + lineHeight / 2) * step;
        for (int y = drawStart; y < drawEnd; y++)
        {
            int texY = (int)texPos & (texHeight - 1);
            texPos += step;
            int color = info->texture[texNum][texHeight * texY + texX];
            if (side == 1)
                color = (color >> 1) & 8355711;
            info->buf[y][x] = color;
        }
		printf("_______________________________________\n");
        x++;
    }

}

int key_press(int key, t_info *info)
{
    // WS
    if (key == KEY_W)
    {
        if (!worldMap[(int)(info->playerPositionX + info->directionVectorX * info->moveSpeed)][(int)(info->playerPositionY)])
            info->playerPositionX += info->directionVectorX * info->moveSpeed;
        if (!worldMap[(int)(info->playerPositionX)][(int)(info->playerPositionY + info->directionVectorY * info->moveSpeed)])
            info->playerPositionY += info->directionVectorY * info->moveSpeed;
    }
    if (key == KEY_S)
    {
        if (!worldMap[(int)(info->playerPositionX - info->directionVectorX * info->moveSpeed)][(int)(info->playerPositionY)])
            info->playerPositionX -= info->directionVectorX * info->moveSpeed;
        if (!worldMap[(int)(info->playerPositionX)][(int)(info->playerPositionY - info->directionVectorY * info->moveSpeed)])
            info->playerPositionY -= info->directionVectorY * info->moveSpeed;
    }
    if (key == KEY_A)
    {
        double oldDirectionX = info->directionVectorX;
        info->directionVectorX = info->directionVectorX * cos(info->rotSpeed) - info->directionVectorY * sin(info->rotSpeed);
        info->directionVectorY = oldDirectionX * sin(info->rotSpeed) + info->directionVectorY * cos(info->rotSpeed);
        double oldPlaneX = info->planeX;
        info->planeX = info->planeX * cos(info->rotSpeed) - info->planeY * sin(info->rotSpeed);
        info->planeY = oldPlaneX * sin(info->rotSpeed) + info->planeY * cos(info->rotSpeed);
    }
    if (key == KEY_D)
    {
        double oldDirectionX = info->directionVectorX;
        info->directionVectorX = info->directionVectorX * cos(-info->rotSpeed) - info->directionVectorY * sin(-info->rotSpeed);
        info->directionVectorY = oldDirectionX * sin(-info->rotSpeed) + info->directionVectorY * cos(-info->rotSpeed);
        double oldPlaneX = info->planeX;
        info->planeX = info->planeX * cos(-info->rotSpeed) - info->planeY * sin(-info->rotSpeed);
        info->planeY = oldPlaneX * sin(-info->rotSpeed) + info->planeY * cos(-info->rotSpeed);
    }
    if (key == K_ESC)
        exit(0);
    return (0);
}

void    load_image(t_info *info, int *texture, char *path, t_img *img)
{
    img->img = mlx_xpm_file_to_image(info->mlx, path, &img->img_width, &img->img_height);
    img->data = (int *)mlx_get_data_addr(img->img, &img->bpp, &img->size_l, &img->endian);
    for (int y = 0; y < img->img_height; y++)
    {
        for (int x = 0; x < img->img_width; x++)
        {
            texture[img->img_width * y + x] = img->data[img->img_width * y + x];
        }
    }
    mlx_destroy_image(info->mlx, img->img);
}

void    load_texture(t_info *info)
{
    t_img    img;

    load_image(info, info->texture[0], "textures/eagle.xpm", &img);
    load_image(info, info->texture[1], "textures/redbrick.xpm", &img);
    load_image(info, info->texture[2], "textures/purplestone.xpm", &img);
    load_image(info, info->texture[3], "textures/greystone.xpm", &img);
    load_image(info, info->texture[4], "textures/bluestone.xpm", &img);
    load_image(info, info->texture[5], "textures/mossy.xpm", &img);
    load_image(info, info->texture[6], "textures/wood.xpm", &img);
    load_image(info, info->texture[7], "textures/colorstone.xpm", &img);
}

int main()
{
    t_info info;
    info.mlx = mlx_init();

    // info는 아래 필드 모두를 가지고 있다.
    info.playerPositionX = 22.0;
    info.playerPositionY = 11.5;
    info.directionVectorX = -1.0;
    info.directionVectorY = 0.0;
    info.planeX = 0.0;
    info.planeY = 0.66;
    info.moveSpeed = 0.05;
    info.rotSpeed = 0.05;


    if (!(info.texture = (int **)malloc(sizeof(int *) * 8)))
        return (-1);
    for (int i = 0; i < 8; i++)
        if (!(info.texture[i] = (int *)malloc(sizeof(int) * (texHeight * texWidth))))
            return (-1);

    for (int i = 0; i < 8; i++)
        for (int j = 0; j < texHeight * texWidth; j++)
            info.texture[i][j] = 0;

    for (int i = 0; i < 8; i++)
        for (int j = 0; j < texHeight * texWidth; j++)
            info.texture[i][j] = 0;

    load_texture(&info);

    // textured에서 추가된 코드 세 줄.
    info.win = mlx_new_window(info.mlx, screenWidth, screenHeight, "mlx");
    info.img.img = mlx_new_image(info.mlx, screenWidth, screenHeight);
    info.img.data = (int *)mlx_get_data_addr(info.img.img, &info.img.bpp, &info.img.size_l, &info.img.endian);

    // 아래 코드들이 무슨 역할을 하는 지 궁금하다면 아래 링크에서 정리해둔 내용을 보자.
    // https://42kchoi.tistory.com/229
    mlx_loop_hook(info.mlx, &main_loop, &info);
    mlx_hook(info.win, X_EVENT_KEY_PRESS, 0, &key_press, &info);
    mlx_loop(info.mlx);
}