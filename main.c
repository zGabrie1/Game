#include "raylib.h"
#include <stdio.h>

//-------------------objects-----------------
typedef struct {
    float x;
    float y;
} Player;
//-------------------------------------------

//---------------functions-------------------
void moviment(Player *playerMoviment) {
    if (IsKeyDown(KEY_RIGHT)) playerMoviment->x += 2.0f;
    if (IsKeyDown(KEY_LEFT)) playerMoviment->x -= 2.0f;
    if (IsKeyDown(KEY_UP)) playerMoviment->y -= 2.0f;
    if (IsKeyDown(KEY_DOWN)) playerMoviment->y += 2.0f;
}



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
        moviment(&player1);
        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(BLACK);

            DrawCircle(player1.x, player1.y, 15, RAYWHITE);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}