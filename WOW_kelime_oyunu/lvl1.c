
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
                   if(IsAUsed==0){
                   SelectedWord[i]='K';
                   i++;
                   IsAUsed=1;
                   }
               }
               if(CheckCollisionPointCircle(Mvec,Bvec,50))
               {
                 
                   if(IsBUsed==0){
                   SelectedWord[i]='U';
                   i++;
                   IsBUsed=1;
                   }
               }
               if(CheckCollisionPointCircle(Mvec,Cvec,50))
               {
                   
                   if(IsCUsed==0){
                   SelectedWord[i]='Y';
                   i++;
                   IsCUsed=1;
                   }
               }
               if(CheckCollisionPointCircle(Mvec,Dvec,50))
               {
                   
                   if(IsDUsed==0){
                   SelectedWord[i]='O';
                   i++;
                   IsDUsed=1;
                   }
               }
               SelectedWord[i]='\0';
       }
       if(IsMouseButtonReleased(0))
       {   
        if(strcmp(SelectedWord,"OYKU")==0)
        {
            Kelime1=true;
        }
        if(strcmp(SelectedWord,"KOY")==0)
        {
            Kelime2=true;
        }
        if(strcmp(SelectedWord,"YUK")==0)
        {
            Kelime3=true;
        }
        IsAUsed=0;
        IsBUsed=0;
        IsCUsed=0;
        IsDUsed=0;
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
       DrawText("U",Bvec.x-10,Bvec.y-20,50,(Color){0,0,0,255});
       DrawText("Y",Cvec.x-10,Cvec.y-20,50,(Color){0,0,0,255});
       DrawText("O",Dvec.x-10,Dvec.y-20,50,(Color){0,0,0,255});
}

void BolumCizLvl1(bool Kelime1,bool Kelime2,bool Kelime3)
{   
    
    if(Kelime1!=false)
       {
           DrawText("OYKU",300,300,50,(Color){255,255,255,255});
       }
       if(Kelime2!=false)
       {
           DrawText("K\n\n\nO\n\n\nY",300,255,50,(Color){255,255,255,255});
       }
       if(Kelime3!=false)
       {
           DrawText("Y\n\n\nU\n\n\nK",405,255,50,(Color){255,255,255,255});
       }
}
