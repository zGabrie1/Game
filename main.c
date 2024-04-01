#include "raylib.h"
#include <stdio.h>

//-------------------objects-----------------
typedef struct {
    float x;
    float y;
} Player;
//-------------------------------------------

//---------------functions-------------------




int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;

    Player player1;
    player1.x = (float)screenWidth/2;
    player1.y = (float)screenHeight/2;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //--------------------------------------------------------------------------------

        if (IsKeyDown(KEY_RIGHT)) player1.x += 2.0f;
        if (IsKeyDown(KEY_LEFT)) player1.x -= 2.0f;
        if (IsKeyDown(KEY_UP)) player1.y -= 2.0f;
        if (IsKeyDown(KEY_DOWN)) player1.y += 2.0f;

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);

            DrawCircle(player1.x, player1.y, 15, BLACK);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}