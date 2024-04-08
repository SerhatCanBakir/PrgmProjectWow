

    int i=0;
    bool IsAUsed=0;
    bool IsBUsed=0;
    bool IsCUsed=0;
    bool IsDUsed=0;
    bool Kelime1=false;

void CoreGamePlayOlusturLvl1(char *SelectedWord,Vector2 Avec,Vector2 Bvec,Vector2 Cvec,Vector2 Dvec,Vector2 Mvec)
{
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
                   SelectedWord[i]='B';
                   i++;
                   IsBUsed=1;
                   }
               }
               if(CheckCollisionPointCircle(Mvec,Cvec,50))
               {
                   
                   if(IsCUsed==0){
                   SelectedWord[i]='C';
                   i++;
                   IsCUsed=1;
                   }
               }
               if(CheckCollisionPointCircle(Mvec,Dvec,50))
               {
                   
                   if(IsDUsed==0){
                   SelectedWord[i]='D';
                   i++;
                   IsDUsed=1;
                   }
               }
               SelectedWord[i]='\0';
       }
       if(IsMouseButtonReleased(0))
       {   
        if(strcmp(SelectedWord,"ABCD")==0)
        {
            Kelime1=true;
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

void AltDaireCizLvl1()
{
       DrawCircle(360,920,200,(Color){ 80, 80, 80, 200 });
       DrawCircle(360,1020,50,(Color){255,255,255,180});
       DrawCircle(360,820,50,(Color){255,255,255,180});
       DrawCircle(260,920,50,(Color){255,255,255,180});
       DrawCircle(460,920,50,(Color){255,255,255,180});
       DrawText("A",350,800,50,(Color){0,0,0,255});
       DrawText("B",350,1000,50,(Color){0,0,0,255});
       DrawText("C",240,900,50,(Color){0,0,0,255});
       DrawText("D",450,900,50,(Color){0,0,0,255});
}

void BolumCizLvl1()
{
    if(Kelime1!=false)
       {
           DrawText("ABCD",300,300,50,(Color){255,255,255,255});
       }
}