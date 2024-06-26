#include "raylib.h"
#include <stdio.h>
#include <math.h>

//-------------------objects-----------------
typedef struct {

    int uprightX;
    int upleftX;
    int upY;
    
    int bottomrightX;
    int bottomleftX;
    int bottomY;

} Object;

//-------------------------------------------

//---------------functions-------------------
void moviment(Vector2 *playerMoviment, int screenW, int screenH, Object object);
//-------------------------------------------

int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;
    int playerSize = 15;

    Vector2 player1;
    player1.x = (float)screenWidth/2;
    player1.y = (float)screenHeight/2;

    Object object1;
    object1.upleftX = 300 - playerSize;
    object1.uprightX = 300 + 400 + playerSize;
    object1.upY = 300 - playerSize;
    object1.bottomY = 300 + 10 + playerSize;

    InitWindow(screenWidth, screenHeight, "I'm goin in an adventure");

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

        moviment(&player1, screenWidth, screenHeight, object1);
        
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

void moviment(Vector2 *playerMoviment, int screemW, int screemH, Object object) {

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
    //--------------UPSIDE-------------------------
    if (IsKeyDown(KEY_DOWN)) {
        if ((playerMoviment->y > object.upY) && 
            (playerMoviment->y < object.bottomY) && 
            ((playerMoviment->x < object.uprightX) && 
            (playerMoviment->x > object.upleftX))) {
            playerMoviment->y -= 3.0f;
        }
    }
    //--------------DOWNSIDE-----------------------
    if (IsKeyDown(KEY_UP)) {
        if ((playerMoviment->y < object.bottomY) && 
            (playerMoviment->y > object.upY) && 
            ((playerMoviment->x < object.uprightX) && 
            (playerMoviment->x > object.upleftX))) {
            playerMoviment->y += 3.0f;
        }
    }

    //-------------SIDES PRESSING UP OR DOWN--------

    if (IsKeyDown(KEY_DOWN)) {
        if ((playerMoviment->x < object.uprightX) && 
            (playerMoviment->x > object.upleftX) && 
            ((playerMoviment->y > object.upY) && 
            (playerMoviment->y < object.bottomY))) {
            playerMoviment->y += 3.0f;
        }
    }

    if (IsKeyDown(KEY_UP)) {
        if ((playerMoviment->x < object.uprightX) && 
            (playerMoviment->x > object.upleftX) && 
            ((playerMoviment->y > object.upY) && 
            (playerMoviment->y < object.bottomY))) {
            playerMoviment->y -= 3.0f;
        }
    }

    //--------------RIGHTSIDE-----------------------
    if (IsKeyDown(KEY_LEFT)) {
        if ((playerMoviment->x > object.upleftX) && 
            (playerMoviment->x < object.uprightX) && 
            ((playerMoviment->y > object.upY) && 
            (playerMoviment->y < object.bottomY))) {
            playerMoviment->x += 3.0f;
        }
    }
    //--------------LEFTSIDE-----------------------
    if (IsKeyDown(KEY_RIGHT)) {
        if ((playerMoviment->x < object.uprightX) && 
            (playerMoviment->x > object.upleftX) && 
            ((playerMoviment->y > object.upY) && 
            (playerMoviment->y < object.bottomY))) {
            playerMoviment->x -= 3.0f;
        }
    }

}