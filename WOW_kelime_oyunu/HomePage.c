int ComlitedLvl=0;
void HomePageCiz()
{
   
 if(ComlitedLvl%10>=1)
     {
     DrawRectangle(100,150,150,150,(Color){0,200,0,255});
     }
 else
     { 

      DrawRectangle(100,150,150,150,(Color){250,250,250,255});
     }
 
 DrawText("1",130,150,100,(Color){0,0,0,255});
 if(ComlitedLvl%100>=10){
     DrawRectangle(470,150,150,150,(Color){0,250,0,255});
 }
 else
 {
 DrawRectangle(470,150,150,150,(Color){250,250,250,255});
 }
 DrawText("2",500,150,100,(Color){0,0,0,255});
 if(ComlitedLvl%1000>=100)
 {
     DrawRectangle(100,350,150,150,(Color){0,250,0,255});
 }else{
 DrawRectangle(100,350,150,150,(Color){250,250,250,255});}
 DrawText("3",130,350,100,(Color){0,0,0,255});
 DrawRectangle(285,550,150,150,(Color){250,250,250,255});
 DrawText("X",315,550,100,(Color){0,0,0,255});
 if(ComlitedLvl&10000>=1000){
     DrawRectangle(470,350,150,150,(Color){0,250,0,255});
 }else{
 DrawRectangle(470,350,150,150,(Color){250,250,250,255});}
 DrawText("4",500,350,100,(Color){0,0,0,255});
}

void HomePageBolumSec(Vector2 Mvec,int *LvlSelector)
{  if(IsMouseButtonPressed(0))
    {
    Mvec=GetMousePosition();
    if(CheckCollisionPointRec(Mvec,(Rectangle){100,150,150,150})!=false)
        {
            *LvlSelector=1;
        }
         if(CheckCollisionPointRec(Mvec,(Rectangle){470,150,150,150})!=false)
        {
            *LvlSelector=2;
        }
         if(CheckCollisionPointRec(Mvec,(Rectangle){100,350,150,150})!=false)
        {
            *LvlSelector=3;
        }
         if(CheckCollisionPointRec(Mvec,(Rectangle){470,350,150,150})!=false)
        {
            *LvlSelector=4;
        }
         if(CheckCollisionPointRec(Mvec,(Rectangle){285,550,150,150})!=false)
        {
            *LvlSelector=5;
        }
    }
}

void ReturnTheHomePage(Vector2 Mvec,int *LvlSelector)
{
    Rectangle R1 ={20,20,150,150};
DrawText("<-",20,20,150,(Color){255,255,255,255});
if(CheckCollisionPointRec(Mvec,R1)==1&&IsMouseButtonPressed(0)){
*LvlSelector=0;
ComlitedLvl=GetDataToFile();
   }
}