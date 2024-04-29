
void VectorDegisLvl1(Vector2 *Avec,Vector2 *Bvec,Vector2 *Cvec,Vector2 *Dvec)
{
    Avec->x =360;
    Avec->y =820;
    Bvec->x=360;
    Bvec->y=1020;
    Cvec->x=260;
    Cvec->y=920;
    Dvec->x=460;
    Dvec->y=920;
} 
    

void CoreGamePlayOlusturLvl1(char *SelectedWord,Vector2 Mvec,Vector2 Avec,Vector2 Bvec,Vector2 Cvec,Vector2 Dvec,bool *Kelime1,bool *Kelime2,bool *Kelime3)
{   
static bool IsAUsed=0;
static    bool IsBUsed=0;
static    bool IsCUsed=0;
static    bool IsDUsed=0;
static int i=0;
    Mvec=GetMousePosition(); 
    if(IsMouseButtonDown(0))
       {
           if(CheckCollisionPointCircle(Mvec,Avec,50))
               {   
                   if(IsAUsed==false){
                   SelectedWord[i]='K';
                   i++;
                   IsAUsed=true;
                   }
               }
               if(CheckCollisionPointCircle(Mvec,Bvec,50))
               {
                 
                   if(IsBUsed==false){
                   SelectedWord[i]='U';
                   i++;
                   IsBUsed=true;
                   }
               }
               if(CheckCollisionPointCircle(Mvec,Cvec,50))
               {
                   
                   if(IsCUsed==false){
                   SelectedWord[i]='Y';
                   i++;
                   IsCUsed=true;
                   }
               }
               if(CheckCollisionPointCircle(Mvec,Dvec,50))
               {
                   
                   if(IsDUsed==false){
                   SelectedWord[i]='O';
                   i++;
                   IsDUsed=true;
                   }
               }
               SelectedWord[i]='\0';
       }
       if(IsMouseButtonReleased(0))
       {   
        if(strcmp(SelectedWord,"OYKU")==0)
        {
            *Kelime1=true;
        }
        if(strcmp(SelectedWord,"KOY")==0)
        {
            *Kelime2=true;
        }
        if(strcmp(SelectedWord,"YUK")==0)
        {
            *Kelime3=true;
        }
        IsAUsed=false;
        IsBUsed=false;
        IsCUsed=false;
        IsDUsed=false;
       SelectedWord[0]=' ';
       SelectedWord[1]='\0';
       i=0;
       }
}

void AltDaireCizLvl1(Vector2 Avec,Vector2 Bvec,Vector2 Cvec,Vector2 Dvec)
{     
       DrawRectangle(270,600,180,60,(Color){255,255,255,150});
       DrawCircle(360,920,200,(Color){ 80, 80, 80, 200 });
       DrawCircleV(Bvec,50,(Color){255,255,255,180});
       DrawCircleV(Avec,50,(Color){255,255,255,180});
       DrawCircleV(Cvec,50,(Color){255,255,255,180});
       DrawCircleV(Dvec,50,(Color){255,255,255,180});
       DrawText("K",Avec.x-10,Avec.y-20,50,(Color){0,0,0,255});
       DrawText("Ü",Bvec.x-10,Bvec.y-20,50,(Color){0,0,0,255});
       DrawText("Y",Cvec.x-10,Cvec.y-20,50,(Color){0,0,0,255});
       DrawText("Ö",Dvec.x-10,Dvec.y-20,50,(Color){0,0,0,255});
}

void BolumCizLvl1(bool *Kelime1,bool *Kelime2,bool *Kelime3,Vector2 Mvec,int *Lvlselector)
{   
    DrawRectangle(170,290,90,90,(Color) {127,0,255,255});
    DrawRectangle(270,290,90,90,(Color) {127,0,255,255});
    DrawRectangle(370,290,90,90,(Color) {127,0,255,255});
    DrawRectangle(470,290,90,90,(Color) {127,0,255,255});
    DrawRectangle(170,390,90,90,(Color) {127,0,255,255});
    DrawRectangle(170,190,90,90,(Color) {127,0,255,255});
    DrawRectangle(470,390,90,90,(Color) {127,0,255,255});
    DrawRectangle(470,190,90,90,(Color) {127,0,255,255});
    if(*Kelime1==true)
       {   
           
           DrawText("Ö Y K Ü",180,290,90,(Color){255,255,255,255});
       }
       if(*Kelime2==true)
       {
           DrawText("K\n\n\n\n\n\nÖ\n\n\n\n\n\nY",180,200,90,(Color){255,255,255,255});
       }
       if(*Kelime3==true)
       {
           DrawText("Y\n\n\n\n\n\nÜ\n\n\n\n\n\nK",480,200,90,(Color){255,255,255,255});
       }
       if(*Kelime1==true && *Kelime2==true && *Kelime3==true )
       {
           DrawRectangle(100,200,500,400,(Color){0,0,0,255});
           DrawText("Sonraki Bolum",100,300,50,(Color){255,0,0,255});
           if(CheckCollisionPointRec(Mvec,(Rectangle){100,200,500,400})&&IsMouseButtonPressed(0))
               {
                   *Lvlselector+=1;
                   *Kelime1=false;
                   *Kelime2=false;
                   *Kelime3=false;
                   IncreaseFileA(1);
                   
               }
}}
       
        void CizgiCizLvl1(char *SelectedWord,Vector2 Avec,Vector2 Bvec,Vector2 Cvec,Vector2 Dvec,Vector2 Mvec)
       {  static int i=0;
          Vector2 temp;
          if(IsMouseButtonDown(0)){
          switch(SelectedWord[i+1])
          {
              case 'K': temp=Avec;
              break;
              case 'U' : temp=Bvec;
              break;
              case 'Y': temp=Cvec;
              break;
              case 'O': temp=Dvec;
              break;
              case '\0': temp=Mvec;
              break;
          }
           switch(SelectedWord[i])
           {  
              
               case 'K' : DrawLineEx(Avec,temp,20,(Color){0,0,0,150});DrawCircleV(temp,20,(Color){0,0,0,150});
               if(temp.x!=Mvec.x&&temp.y!=Mvec.y){i++; CizgiCizLvl1(SelectedWord,Avec,Bvec,Cvec,Dvec,Mvec);}
               break;
               case 'U' : DrawLineEx(Bvec,temp,20,(Color){0,0,0,150});DrawCircleV(temp,20,(Color){0,0,0,150});
               if(temp.x!=Mvec.x&&temp.y!=Mvec.y){i++;CizgiCizLvl1(SelectedWord,Avec,Bvec,Cvec,Dvec,Mvec);}
               break;
               case 'Y' : DrawLineEx(Cvec,temp,20,(Color){0,0,0,150});DrawCircleV(temp,20,(Color){0,0,0,150});
               if(temp.x!=Mvec.x&&temp.y!=Mvec.y){i++;CizgiCizLvl1(SelectedWord,Avec,Bvec,Cvec,Dvec,Mvec);}
               break;
               case 'O' : DrawLineEx(Dvec,temp,20,(Color){0,0,0,150});DrawCircleV(temp,20,(Color){0,0,0,150});
               if(temp.x!=Mvec.x&&temp.y!=Mvec.y){i++;CizgiCizLvl1(SelectedWord,Avec,Bvec,Cvec,Dvec,Mvec);}
               break;
          }
          }
          i =0;
       } 
