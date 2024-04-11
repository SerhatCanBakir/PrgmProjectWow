
#include "raylib.h"
#include "lvl1.c"
#include "lvl2.c"
#include "HomePage.c"
#include "lvl3.c"
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
   char SelectedWord[10]=" ";
   Vector2 Avec={360,820},Bvec={360,1020},Cvec={260,920},Dvec={460,920};
   Vector2 Mvec; 
  SetMousePosition(360,920);
  VectorDegisLvl2(&Avec,&Bvec,&Cvec);
  bool Kelime1=false,Kelime2=false,Kelime3=false,Kelime4=false;
  int LvlSelector=0;
    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    { Mvec=GetMousePosition();
        // Updatm
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
       switch(LvlSelector)
       {
           case 0:HomePageBolumSec(Mvec,&LvlSelector);
           break;
           case 1:VectorDegisLvl1(&Avec,&Bvec,&Cvec,&Dvec);
           CoreGamePlayOlusturLvl1(SelectedWord,Mvec,Avec,Bvec,Cvec,Dvec,&Kelime1,&Kelime2,&Kelime3);
           break;
           case 2:VectorDegisLvl2(&Avec,&Bvec,&Cvec);
            CoreGamePlayOlusturLvl2(SelectedWord,Mvec,Avec,Bvec,Cvec,&Kelime1,&Kelime2);
            break;
            case 3:VectorDegisLvl3(&Avec,&Bvec,&Cvec,&Dvec);
            CoreGamePlayOlusturLvl3(SelectedWord,Mvec,Avec,Bvec,Cvec,Dvec,&Kelime1,&Kelime2,&Kelime3,&Kelime4);
            break;
           default:
           break;
           
       } 
   
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();
       
       ClearBackground((Color){250,250,250,250});
       DrawTexture(texture,0,0,(Color){250,250,250,250});
       DrawText(SelectedWord,280,600,50,(Color){0,0,0,250});
       switch(LvlSelector)
       {
           case 0:
           HomePageCiz();
           break;
           case 1: AltDaireCizLvl1(Avec,Bvec,Cvec,Dvec);
           BolumCizLvl1(&Kelime1,&Kelime2,&Kelime3,Mvec,&LvlSelector);
           break;
           case 2:AltDaireCizLvl2(Avec,Bvec,Cvec);
           BolumCizLvl2(&Kelime1,&Kelime2,Mvec,&LvlSelector);
           break;
           case 3:AltDaireCizLvl3(Avec,Bvec,Cvec,Dvec);
           BolumCizLvl3(&Kelime1,&Kelime2,&Kelime3,&Kelime4,Mvec,&LvlSelector);
           break;
       }
        EndDrawing();
        //----------------------------------------------------------------------------------
        
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
