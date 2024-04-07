
#include "raylib.h"


//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 720;
    const int screenHeight = 1280;

    InitWindow(screenWidth, screenHeight, "WOW GAME");
    Image resim = LoadImage("resorce/BackGround.png");
    Texture2D texture = LoadTextureFromImage(resim);
    UnloadImage(resim);
    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    { 
        // Updatm
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();
       
       ClearBackground((Color){250,250,250,250});
       DrawTexture(texture,0,0,(Color){250,250,250,250});
       

        EndDrawing();
        //----------------------------------------------------------------------------------
        
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}