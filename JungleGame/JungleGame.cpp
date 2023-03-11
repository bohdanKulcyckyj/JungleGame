#include <iostream>
#include <string>
#include <vector>

#include "raylib.h"

using namespace std;

vector <Texture2D> loadBackgroudLayers(vector<string> paths, int w, int h) {
    vector<Texture2D> backgroundLayers;
    Image tmp;

    for (string path : paths) {
        //load image from path
        tmp = LoadImage(path.c_str()); //c_str for conversion sting to const char*

        //resize image
        ImageResize(&tmp, w, h);

        //load texture from image & push to vector
        backgroundLayers.push_back(LoadTextureFromImage(tmp));
    }

    return backgroundLayers;
}


int main()

{
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);

    const int screenWidth = 1900; //GetScreenWidth();
    const int screenHeight = 1100; //GetScreenHeight();

    InitWindow(screenWidth, screenHeight, "My First Game");

    vector<string> backgroundPaths;
    backgroundPaths.push_back("./resources/Layer_0000_9.png");
    backgroundPaths.push_back("./resources/Layer_0001_8.png");
    backgroundPaths.push_back("./resources/Layer_0002_7.png");
    backgroundPaths.push_back("./resources/Layer_0003_6.png");
    backgroundPaths.push_back("./resources/Layer_0004_Lights.png");
    backgroundPaths.push_back("./resources/Layer_0005_5.png");
    backgroundPaths.push_back("./resources/Layer_0006_4.png");
    backgroundPaths.push_back("./resources/Layer_0007_Lights.png");
    backgroundPaths.push_back("./resources/Layer_0008_3.png");
    backgroundPaths.push_back("./resources/Layer_0009_2.png");
    backgroundPaths.push_back("./resources/Layer_0010_1.png");
    backgroundPaths.push_back("./resources/Layer_0011_0.png");

    reverse(backgroundPaths.begin(), backgroundPaths.end());

    float scrollingBack = 0.0f;
    float scrollingMid = 0.0f;
    float scrollingFore = 0.0f;
    float scrollingForeFore = 0.0f;

    SetTargetFPS(60);

    ToggleFullscreen();

    vector<Texture2D> gameBg = loadBackgroudLayers(backgroundPaths, GetScreenWidth(), GetScreenHeight());
    //--------------------------------------------------------------------------------------

    //game loop
    while (!WindowShouldClose()) // Detect window close button or ESC key
    {
        // Update
        scrollingBack -= 0.1f;
        scrollingMid -= 0.5f;
        scrollingFore -= 1.0f;
        scrollingForeFore -= 1.2f;

        // NOTE: Texture is scaled twice its size, so it sould be considered on scrolling
        if (scrollingBack <= -gameBg[0].width * 2) scrollingBack = 0;
        if (scrollingMid <= -gameBg[0].width * 2) scrollingMid = 0;
        if (scrollingFore <= -gameBg[0].width * 2) scrollingFore = 0;
        if (scrollingForeFore <= -gameBg[0].width * 2) scrollingForeFore = 0;

        // Draw
        BeginDrawing();

        if (IsKeyPressed(KEY_SPACE)) {
            ToggleFullscreen();
        }

        //ClearBackground(GetColor(0xffffff));

        // Draw background image twice
        // NOTE: Texture is scaled twice its size
        for (int i = 0; i < gameBg.size(); i++) {
            float speed;

            if (i < 3) {
                speed = scrollingBack;
            }
            else if (i < 6) {
                speed = scrollingMid;
            }
            else if (i == 12) {
                speed = scrollingForeFore;
            }
            else {
                speed = scrollingFore;
            }


            DrawTextureEx(gameBg[i], { speed, ((float)GetScreenHeight() * (-1.0f)) }, 0.0f, 2.0f, WHITE);
            DrawTextureEx(gameBg[i], { gameBg[i].width * 2 + speed, ((float)GetScreenHeight() * (-1.0f)) }, 0.0f, 2.0f, WHITE);
        }

        DrawText("Jungle Game", 10, 10, 40, RAYWHITE);
        DrawText("Made by Behdon", GetScreenWidth() - 200, GetScreenHeight() - 50, 10, RAYWHITE);

        EndDrawing();
    }

    // De-Initialization
    for (Texture2D t : gameBg) {
        UnloadTexture(t);
    }

    CloseWindow();// Close window and OpenGL context

    return 0;
}