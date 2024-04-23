void VectorDegisLvl3(Vector2 *Avec,Vector2 *Bvec,Vector2 *Cvec,Vector2 *Dvec)
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
void CoreGamePlayOlusturLvl3(char *SelectedWord,Vector2 Mvec,Vector2 Avec,Vector2 Bvec,Vector2 Cvec,Vector2 Dvec,bool *Kelime1,bool *Kelime2,bool *Kelime3,bool *Kelime4)
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
                   SelectedWord[i]='C';
                   i++;
                   IsAUsed=true;
                   }
               }
               if(CheckCollisionPointCircle(Mvec,Bvec,50))
               {
                 
                   if(IsBUsed==false){
                   SelectedWord[i]='L';
                   i++;
                   IsBUsed=true;
                   }
               }
               if(CheckCollisionPointCircle(Mvec,Cvec,50))
               {
                   
                   if(IsCUsed==false){
                   SelectedWord[i]='E';
                   i++;
                   IsCUsed=true;
                   }
               }
               if(CheckCollisionPointCircle(Mvec,Dvec,50))
               {
                   
                   if(IsDUsed==false){
                   SelectedWord[i]='I';
                   i++;
                   IsDUsed=true;
                   }
               }
               SelectedWord[i]='\0';
       }
       if(IsMouseButtonReleased(0))
       {   
        if(strcmp(SelectedWord,"CILE")==0)
        {
            *Kelime1=true;
        }
        if(strcmp(SelectedWord,"CIL")==0)
        {
            *Kelime2=true;
        }
        if(strcmp(SelectedWord,"ILCE")==0)
        {
            *Kelime3=true;
        }
        if(strcmp(SelectedWord,"ELCI")==0)
        {
            *Kelime4=true;
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

void AltDaireCizLvl3(Vector2 Avec,Vector2 Bvec,Vector2 Cvec,Vector2 Dvec)
{     
       DrawRectangle(270,600,180,60,(Color){255,255,255,150});
       DrawCircle(360,920,200,(Color){ 80, 80, 80, 200 });
       DrawCircleV(Bvec,50,(Color){255,255,255,180});
       DrawCircleV(Avec,50,(Color){255,255,255,180});
       DrawCircleV(Cvec,50,(Color){255,255,255,180});
       DrawCircleV(Dvec,50,(Color){255,255,255,180});
       DrawText("Ç",Avec.x-10,Avec.y-20,50,(Color){0,0,0,255});
       DrawText("L",Bvec.x-10,Bvec.y-20,50,(Color){0,0,0,255});
       DrawText("E",Cvec.x-10,Cvec.y-20,50,(Color){0,0,0,255});
       DrawText("I",Dvec.x-10,Dvec.y-20,50,(Color){0,0,0,255});
}

void BolumCizLvl3(bool *Kelime1,bool *Kelime2,bool *Kelime3,bool *Kelime4,Vector2 Mvec,int *Lvlselector)
{   
    DrawRectangle(90,190,90,90,(Color) {127,0,255,255});
    DrawRectangle(90,290,90,90,(Color) {127,0,255,255});
    DrawRectangle(90,390,90,90,(Color) {127,0,255,255});
    DrawRectangle(90,490,90,90,(Color) {127,0,255,255});
    DrawRectangle(190,490,90,90,(Color) {127,0,255,255});
    DrawRectangle(290,490,90,90,(Color) {127,0,255,255});
    DrawRectangle(390,490,90,90,(Color) {127,0,255,255});
    DrawRectangle(390,390,90,90,(Color) {127,0,255,255});
    DrawRectangle(390,290,90,90,(Color) {127,0,255,255});
    DrawRectangle(390,190,90,90,(Color) {127,0,255,255});
    DrawRectangle(290,290,90,90,(Color) {127,0,255,255});
    DrawRectangle(490,290,90,90,(Color) {127,0,255,255});
    
    if(*Kelime1==true)
       {
           DrawText("Ç\n\n\n\n\n\nI\n\n\n\n\n\n\nL\n\n\n\n\n\n\nE",400,200,90,(Color){255,255,255,255});
       }
       if(*Kelime2==true)
       {
           DrawText("Ç I  L",300,290,90,(Color){255,255,255,255});
       }
       if(*Kelime3==true)
       {
           DrawText("I  L Ç E",100,500,90,(Color){255,255,255,255});
       }
       if(*Kelime4==true)
       {
           DrawText("E\n\n\n\n\n\nL\n\n\n\n\n\n\nÇ\n\n\n\n\n\n\nI",100,200,90,(Color){255,255,255,255});
       }
       if(*Kelime1==true && *Kelime2==true && *Kelime3==true &&*Kelime4==true)
       {
           DrawRectangle(100,200,500,400,(Color){0,0,0,255});
           DrawText("Sonraki Bolum",100,300,50,(Color){255,0,0,255});
           if(CheckCollisionPointRec(Mvec,(Rectangle){100,200,500,400})&&IsMouseButtonPressed(0))
               {
                   *Lvlselector+=1;
                   *Kelime1=false;
                   *Kelime2=false;
                   *Kelime3=false;
                   *Kelime4=false;
               }
       }
}

void CizgiCizLvl3(char *SelectedWord,Vector2 Avec,Vector2 Bvec,Vector2 Cvec,Vector2 Dvec,Vector2 Mvec)
       {  static int i=0;
          Vector2 temp;
          if(IsMouseButtonDown(0)){
          switch(SelectedWord[i+1])
          {
              case 'C': temp=Avec;
              break;
              case 'L' : temp=Bvec;
              break;
              case 'E': temp=Cvec;
              break;
              case 'I': temp=Dvec;
              break;
              case '\0': temp=Mvec;
              break;
          }
           switch(SelectedWord[i])
           {  
              
               case 'C' : DrawLineEx(Avec,temp,20,(Color){0,0,0,100});
               if(temp.x!=Mvec.x&&temp.y!=Mvec.y){i++;CizgiCizLvl3(SelectedWord,Avec,Bvec,Cvec,Dvec,Mvec);}
               break;
               case 'L' : DrawLineEx(Bvec,temp,20,(Color){0,0,0,100});
               if(temp.x!=Mvec.x&&temp.y!=Mvec.y){i++;CizgiCizLvl3(SelectedWord,Avec,Bvec,Cvec,Dvec,Mvec);}
               break;
               case 'E' : DrawLineEx(Cvec,temp,20,(Color){0,0,0,100});
               if(temp.x!=Mvec.x&&temp.y!=Mvec.y){i++;CizgiCizLvl3(SelectedWord,Avec,Bvec,Cvec,Dvec,Mvec);}
               break;
               case 'I' : DrawLineEx(Dvec,temp,20,(Color){0,0,0,100});
               if(temp.x!=Mvec.x&&temp.y!=Mvec.y){i++;CizgiCizLvl3(SelectedWord,Avec,Bvec,Cvec,Dvec,Mvec);}
               break;
          }
          }
          i =0;
       } 
