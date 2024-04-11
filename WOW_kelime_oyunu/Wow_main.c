
#include "raylib.h"
#include "lvl1.c"
#include "lvl2.c"

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
   char SelectedWord[10]="sa";
   Vector2 Avec={360,820},Bvec={360,1020},Cvec={260,920},Dvec={460,920};
   Vector2 Mvec; 
  SetMousePosition(360,920);
  VectorDegisLvl2(&Avec,&Bvec,&Cvec);
  bool Kelime1=false,Kelime2=false,Kelime3=false;
  
    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    { 
        // Updatm
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
       CoreGamePlayOlusturLvl2(SelectedWord,Mvec,Avec,Bvec,Cvec,&Kelime1,&Kelime2);
   
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();
       
       ClearBackground((Color){250,250,250,250});
       DrawTexture(texture,0,0,(Color){250,250,250,250});
       DrawText(SelectedWord,280,600,50,(Color){0,0,0,250});
       AltDaireCizLvl2(Avec,Bvec,Cvec);
       BolumCizLvl2(Kelime1,Kelime2);
        EndDrawing();
        //----------------------------------------------------------------------------------
        
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
