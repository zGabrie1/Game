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
void moviment(Player *playerMoviment, int screemW, int screemH, int objectX, int objectY, int playerSize, int objectW, int objectH);
//-------------------------------------------

int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;
    int playerSize = 15;

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

        moviment(&player1, screenWidth, screenHeight, 300, 300, playerSize, 400, 10);
        
        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(BLACK);
            DrawRectangle(300, 300, 400, 10, WHITE);
            DrawCircle(player1.x, player1.y, playerSize, RED);
            
        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}


void moviment(Player *playerMoviment, int screemW, int screemH, int objectX, int objectY, int playerSize, int objectW, int objectH) {

    if (IsKeyDown(KEY_RIGHT)) {
        if (playerMoviment->x < screemW - 15) {
            playerMoviment->x += 3.0f;
        }
    }
    if (IsKeyDown(KEY_LEFT)) {
        if (playerMoviment->x > 15) {
            playerMoviment->x -= 3.0f;
        }
    }
    if (IsKeyDown(KEY_UP)) {
        if (playerMoviment->y > 15) {
            playerMoviment->y -= 3.0f;
        }
    }
    if (IsKeyDown(KEY_DOWN)) {
        if (playerMoviment->y < screemH - 15) {
            playerMoviment->y += 3.0f;
        }
    }

    //-----------collision with objects------------

    if (IsKeyDown(KEY_DOWN)) {
        if ((playerMoviment->y > objectY - objectH/2 - playerSize + 5) && (playerMoviment->x < objectX + objectW + playerSize) && (playerMoviment->x > objectX - playerSize)) {
            playerMoviment->y -= 3.0f;
        }
    }

}