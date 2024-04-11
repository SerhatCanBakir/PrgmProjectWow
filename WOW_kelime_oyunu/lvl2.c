void VectorDegisLvl2(Vector2 *Avec,Vector2 *Bvec,Vector2 *Cvec)
{
    Avec->x =360;
    Avec->y =820;
    Bvec->x=280;
    Bvec->y=980;
    Cvec->x=440;
    Cvec->y=980;
} 
    

void CoreGamePlayOlusturLvl2(char *SelectedWord,Vector2 Mvec,Vector2 Avec,Vector2 Bvec,Vector2 Cvec,bool *Kelime1,bool *Kelime2)
{  static bool IsAUsed=0;
   static bool IsBUsed=0;
   static bool IsCUsed=0; 
    static int i=0;
    Mvec=GetMousePosition(); 
    if(IsMouseButtonDown(0))
       {
           if(CheckCollisionPointCircle(Mvec,Avec,50))
               {   
                   if(IsAUsed==0){
                   SelectedWord[i]='A';
                   i++;
                   IsAUsed=1;
                   }
               }
               if(CheckCollisionPointCircle(Mvec,Bvec,50))
               {
                 
                   if(IsBUsed==0){
                   SelectedWord[i]='S';
                   i++;
                   IsBUsed=1;
                   }
               }
               if(CheckCollisionPointCircle(Mvec,Cvec,50))
               {
                   
                   if(IsCUsed==0){
                   SelectedWord[i]='K';
                   i++;
                   IsCUsed=1;
                   }
               }
               SelectedWord[i]='\0';
       }
       if(IsMouseButtonReleased(0))
       {   
        if(strcmp(SelectedWord,"KAS")==0)
        {
            *Kelime1=true;
        }
        if(strcmp(SelectedWord,"ASK")==0)
        {
            *Kelime2=true;
        }
       
        IsAUsed=0;
        IsBUsed=0;
        IsCUsed=0;
       SelectedWord[0]=' ';
       SelectedWord[1]='\0';
       i=0;
       }
}

void AltDaireCizLvl2(Vector2 Avec,Vector2 Bvec,Vector2 Cvec)
{     
       DrawRectangle(270,600,180,60,(Color){255,255,255,150});
       DrawCircle(360,920,200,(Color){ 80, 80, 80, 200 });
       DrawCircleV(Avec,50,(Color){255,255,255,180});
       DrawCircleV(Bvec,50,(Color){255,255,255,180});
       DrawCircleV(Cvec,50,(Color){255,255,255,180});
       DrawText("A",Avec.x-10,Avec.y-20,50,(Color){0,0,0,255});
       DrawText("S",Bvec.x-10,Bvec.y-20,50,(Color){0,0,0,255});
       DrawText("K",Cvec.x-10,Cvec.y-20,50,(Color){0,0,0,255});
      
}

void BolumCizLvl2(bool Kelime1,bool Kelime2)
{   
    
    if(Kelime1!=false)
       {
           DrawText("KAS",300,345,50,(Color){255,255,255,255});
       }
       if(Kelime2!=false)
       {
           DrawText("A\n\n\nS\n\n\nK",300,255,50,(Color){255,255,255,255});
       }
       
}