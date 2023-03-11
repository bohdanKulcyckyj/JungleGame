#include <iostream>
#include <string>
#include <vector>
#include "AssetsLoader.h";
#include "Background.h";

#include "raylib.h"

using namespace std;

int main()

{
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);

    const int screenWidth = 1900; //GetScreenWidth();
    const int screenHeight = 1100; //GetScreenHeight();

    InitWindow(screenWidth, screenHeight, "My First Game");



    //reverse(backgroundPaths.begin(), backgroundPaths.end());

    float scrollingBack = 0.0f;
    float scrollingMid = 0.0f;
    float scrollingFore = 0.0f;
    float scrollingForeFore = 0.0f;

    SetTargetFPS(250);

    ToggleFullscreen();

    Background* testBg = new Background("./resources/jungle-background");

    vector<Texture2D> gameBg = testBg->getBackgroundLayers();
    //--------------------------------------------------------------------------------------

    //game loop
    while (!WindowShouldClose()) // Detect window close button or ESC key
    {
        //Control
        if (IsKeyDown(KEY_D)) {
            scrollingBack -= 0.1f;
            scrollingMid -= 0.5f;
            scrollingFore -= 1.0f;
            scrollingForeFore -= 1.2f;

            // NOTE: Texture is scaled twice its size, so it sould be considered on scrolling
            if (scrollingBack <= -gameBg[0].width * 2) scrollingBack = 0;
            if (scrollingMid <= -gameBg[0].width * 2) scrollingMid = 0;
            if (scrollingFore <= -gameBg[0].width * 2) scrollingFore = 0;
            if (scrollingForeFore <= -gameBg[0].width * 2) scrollingForeFore = 0;
        }

        if (IsKeyDown(KEY_A)) {
            scrollingBack += 0.1f;
            scrollingMid += 0.5f;
            scrollingFore += 1.0f;
            scrollingForeFore += 1.2f;

            // NOTE: Texture is scaled twice its size, so it sould be considered on scrolling
            if (scrollingBack >= +gameBg[0].width * 2) scrollingBack = 0;
            if (scrollingMid >= +gameBg[0].width * 2) scrollingMid = 0;
            if (scrollingFore >= +gameBg[0].width * 2) scrollingFore = 0;
            if (scrollingForeFore >= +gameBg[0].width * 2) scrollingForeFore = 0;

        }

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


            //Left
            DrawTextureEx(gameBg[i], { speed - gameBg[i].width * 2, ((float)GetScreenHeight() * (-1.0f)) }, 0.0f, 2.0f, WHITE);
            //Mid
            DrawTextureEx(gameBg[i], { speed, ((float)GetScreenHeight() * (-1.0f)) }, 0.0f, 2.0f, WHITE);
            //Right
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