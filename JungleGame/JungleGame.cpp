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

    SetTargetFPS(250);

    ToggleFullscreen();

    Background* testBg = new Background("./resources/jungle-background");

    vector<Texture2D> gameBg = testBg->getBackgroundLayers();
    //--------------------------------------------------------------------------------------

    //game loop
    while (!WindowShouldClose()) // Detect window close button or ESC key
    {
        //Control
        /*if (IsKeyDown(KEY_D)) {
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

        }*/

        // Draw
        BeginDrawing();

        if (IsKeyPressed(KEY_SPACE)) {
            ToggleFullscreen();
        }

        // Draw background images
        testBg->DrawBackground();

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