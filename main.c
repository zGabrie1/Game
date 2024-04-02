#include "raylib.h"
#include <stdio.h>
#include <math.h>

//-------------------objects-----------------
typedef struct {
    float x;
    float y;
} Player;
//-------------------------------------------

//---------------functions-------------------
void moviment(Player *playerMoviment, int screemW, int screemH);
//-------------------------------------------

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
        

        if(IsKeyDown(KEY_R)) { 
            player1.x = (float)screenWidth/2;
            player1.y = (float)screenHeight/2;
        }
        moviment(&player1, screenWidth, screenHeight);

        
        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(BLACK);

            DrawRectangle(300, 300, 400, 10, WHITE);
            DrawCircle(player1.x, player1.y, 15, RED);
            
        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}


void moviment(Player *playerMoviment, int screemW, int screemH) {
    if(playerMoviment->x <= 15) {
        if (IsKeyDown(KEY_RIGHT)) playerMoviment->x += 3.0f;
        if (IsKeyDown(KEY_LEFT)) playerMoviment->x -= 0.0f;
        if (IsKeyDown(KEY_UP)) playerMoviment->y -= 3.0f;
        if (IsKeyDown(KEY_DOWN)) playerMoviment->y += 3.0f;
    } else if(playerMoviment->x >= screemW - 15) {
        if (IsKeyDown(KEY_RIGHT)) playerMoviment->x += 0.0f;
        if (IsKeyDown(KEY_LEFT)) playerMoviment->x -= 3.0f;
        if (IsKeyDown(KEY_UP)) playerMoviment->y -= 3.0f;
        if (IsKeyDown(KEY_DOWN)) playerMoviment->y += 3.0f;
    } else if(playerMoviment->y <= 15) {
        if (IsKeyDown(KEY_RIGHT)) playerMoviment->x += 3.0f;
        if (IsKeyDown(KEY_LEFT)) playerMoviment->x -= 3.0f;
        if (IsKeyDown(KEY_UP)) playerMoviment->y -= 0.0f;
        if (IsKeyDown(KEY_DOWN)) playerMoviment->y += 3.0f;
    } else if(playerMoviment->y >= screemH - 15) {
        if (IsKeyDown(KEY_RIGHT)) playerMoviment->x += 3.0f;
        if (IsKeyDown(KEY_LEFT)) playerMoviment->x -= 3.0f;
        if (IsKeyDown(KEY_UP)) playerMoviment->y -= 3.0f;
        if (IsKeyDown(KEY_DOWN)) playerMoviment->y += 0.0f;
    } else {
        if (IsKeyDown(KEY_RIGHT)) playerMoviment->x += 3.0f;
        if (IsKeyDown(KEY_LEFT)) playerMoviment->x -= 3.0f;
        if (IsKeyDown(KEY_UP)) playerMoviment->y -= 3.0f;
        if (IsKeyDown(KEY_DOWN)) playerMoviment->y += 3.0f;
    }

}