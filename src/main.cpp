#include <raylib.h>
#include <raymath.h>

#include "headder/easeing.h"

constexpr unsigned short winWidth = 500;
constexpr unsigned short winHeight = 500;

constexpr unsigned short halfWinWidth = winWidth / 2;
constexpr unsigned short halfWinHeight = winHeight / 2;

constexpr unsigned short buttonRad = winWidth * 0.1f;

constexpr unsigned char buttonTravelLen = 10;

int main(){ // Particle effects, Second Button, Auto Clicker
    SetConfigFlags(FLAG_MSAA_4X_HINT);

    InitWindow(winWidth, winHeight, "Hello Raylib");

    SetTargetFPS(60);

    Color bgColor{30, 30, 30, 255};

    static unsigned int points = 0;

    float startTime = 0;
    float duration = 2.0f;
    float startRadius = 0.0f;
    float curRadius = startRadius;
    float overShoot = 5.0f;

    bool startupAnim{true};

    while(!WindowShouldClose()){
        curRadius = easeOutBack(startTime, startRadius, buttonRad, duration, overShoot);

        if (startTime > duration){
            curRadius = buttonRad;
            startupAnim = false;
        }
        else
            startTime += GetFrameTime();

        BeginDrawing();
        ClearBackground(bgColor);

        DrawCircle(halfWinWidth - buttonTravelLen, halfWinHeight + buttonTravelLen, curRadius, (Color{180, 0, 0, 255}));

        if (!startupAnim){
            if (IsKeyDown(KEY_SPACE) || IsMouseButtonDown(MOUSE_BUTTON_LEFT))
                DrawCircle(halfWinWidth - buttonTravelLen, halfWinHeight + buttonTravelLen, buttonRad, RED);
            else
                DrawCircle(halfWinWidth, halfWinHeight, buttonRad, RED);
        }

        if (!startupAnim && IsKeyPressed(KEY_SPACE) || IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            ++points;

        DrawText(TextFormat("POINTS: %i", points), halfWinWidth - (MeasureText(TextFormat("POINTS: %i", points), 20) / 2), 10, 20, RAYWHITE);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}