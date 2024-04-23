void VectorDegisLvl4(Vector2 *Avec,Vector2 *Bvec,Vector2 *Cvec,Vector2 *Dvec)
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
void CoreGamePlayOlusturLvl4(char *SelectedWord,Vector2 Mvec,Vector2 Avec,Vector2 Bvec,Vector2 Cvec,Vector2 Dvec,bool *Kelime1,bool *Kelime2,bool *Kelime3,bool *Kelime4,bool *Kelime5)
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
                   SelectedWord[i]='A';
                   i++;
                   IsAUsed=true;
                   }
               }
               if(CheckCollisionPointCircle(Mvec,Bvec,50))
               {
                 
                   if(IsBUsed==false){
                   SelectedWord[i]='A';
                   i++;
                   IsBUsed=true;
                   }
               }
               if(CheckCollisionPointCircle(Mvec,Cvec,50))
               {
                   
                   if(IsCUsed==false){
                   SelectedWord[i]='D';
                   i++;
                   IsCUsed=true;
                   }
               }
               if(CheckCollisionPointCircle(Mvec,Dvec,50))
               {
                   
                   if(IsDUsed==false){
                   SelectedWord[i]='M';
                   i++;
                   IsDUsed=true;
                   }
               }
               SelectedWord[i]='\0';
       }
       if(IsMouseButtonReleased(0))
       {   
        if(strcmp(SelectedWord,"ADAM")==0)
        {
            *Kelime1=true;
        }
        if(strcmp(SelectedWord,"ADA")==0)
        {
            *Kelime2=true;
        }
        if(strcmp(SelectedWord,"DAM")==0)
        {
            *Kelime3=true;
        }
        if(strcmp(SelectedWord,"DAMA")==0)
        {
            *Kelime4=true;
        }
        if(strcmp(SelectedWord,"AMA")==0)
        {
            *Kelime5=true;
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

void AltDaireCizLvl4(Vector2 Avec,Vector2 Bvec,Vector2 Cvec,Vector2 Dvec)
{     
       DrawRectangle(270,600,180,60,(Color){255,255,255,150});
       DrawCircle(360,920,200,(Color){ 80, 80, 80, 200 });
       DrawCircleV(Bvec,50,(Color){255,255,255,180});
       DrawCircleV(Avec,50,(Color){255,255,255,180});
       DrawCircleV(Cvec,50,(Color){255,255,255,180});
       DrawCircleV(Dvec,50,(Color){255,255,255,180});
       DrawText("A",Avec.x-10,Avec.y-20,50,(Color){0,0,0,255});
       DrawText("A",Bvec.x-10,Bvec.y-20,50,(Color){0,0,0,255});
       DrawText("D",Cvec.x-10,Cvec.y-20,50,(Color){0,0,0,255});
       DrawText("M",Dvec.x-10,Dvec.y-20,50,(Color){0,0,0,255});
}

void BolumCizLvl4(bool *Kelime1,bool *Kelime2,bool *Kelime3,bool *Kelime4,bool *Kelime5,Vector2 Mvec,int *Lvlselector)
{   
    DrawRectangle(190,190,90,90,(Color) {127,0,255,255});
    DrawRectangle(290,190,90,90,(Color) {127,0,255,255});
    DrawRectangle(390,190,90,90,(Color) {127,0,255,255});
    DrawRectangle(490,190,90,90,(Color) {127,0,255,255});
    DrawRectangle(290,290,90,90,(Color) {127,0,255,255});
    DrawRectangle(290,390,90,90,(Color) {127,0,255,255});
    DrawRectangle(290,490,90,90,(Color) {127,0,255,255});
    DrawRectangle(390,490,90,90,(Color) {127,0,255,255});
    DrawRectangle(490,490,90,90,(Color) {127,0,255,255});
    DrawRectangle(190,390,90,90,(Color) {127,0,255,255});
    DrawRectangle(90,390,90,90,(Color) {127,0,255,255});
    DrawRectangle(90,490,90,90,(Color) {127,0,255,255});    
    DrawRectangle(90,290,90,90,(Color) {127,0,255,255});


    if(*Kelime1==true)
       {
           DrawText("A D A M",200,200,90,(Color){255,255,255,255});
       }
       if(*Kelime2==true)
       {
           DrawText("A\n\n\n\n\n\nD\n\n\n\n\n\nA",100,300,90,(Color){255,255,255,255});
       }
       if(*Kelime3==true)
       {
           DrawText("D A M",100,390,90,(Color){255,255,255,255});
       }
       if(*Kelime4==true)
       {
           DrawText("D\n\n\n\n\n\nA\n\n\n\n\n\n\nM\n\n\n\n\n\n\nA",300,200,90,(Color){255,255,255,255});
       }
       if(*Kelime5==true)
       {
           DrawText("A M A",300,500,90,(Color){255,255,255,255});
       }
       if(*Kelime1==true && *Kelime2==true && *Kelime3==true &&*Kelime4==true&&*Kelime5==true)
       {
           DrawRectangle(100,200,500,400,(Color){0,0,0,255});
           DrawText("Proje Bitti",100,300,50,(Color){255,0,0,255});
           if(CheckCollisionPointRec(Mvec,(Rectangle){100,200,500,400})&&IsMouseButtonPressed(0))
               {
                   *Lvlselector+=1;
                   *Kelime1=false;
                   *Kelime2=false;
                   *Kelime3=false;
                   *Kelime4=false;
                   *Kelime5=false;
               }
       }
}

void CizgiCizLvl4(char *SelectedWord,Vector2 Avec,Vector2 Bvec,Vector2 Cvec,Vector2 Dvec,Vector2 Mvec)
       {   
            static int i=0;
            int sayac=0;
          Vector2 temp;
           static int  WhichİsUsed=0;
           int Another=0;
           for(int a=0;SelectedWord[a]!='\0';a++)
           {
               if(SelectedWord[a]=='A')
               {
                   sayac++;
               }
           }
           if(sayac>=2){Another++;}
          if(IsMouseButtonDown(0)){
                
                if(CheckCollisionPointCircle(Mvec,Avec,50)&&WhichİsUsed==0)
                {
                    WhichİsUsed=1;
                }
                else if(CheckCollisionPointCircle(Mvec,Bvec,50)&&WhichİsUsed==0)
                {
                    WhichİsUsed=2;
                }
                
          switch(SelectedWord[i+1])
          {
              case 'A': if(WhichİsUsed==1){temp=Avec;}
              else if(WhichİsUsed==2)
              {temp=Bvec;}
              
              break;
              case 'D': temp=Cvec;
              break;
              case 'M': temp=Dvec;
              break;
              case '\0': temp=Mvec;
              break;
          }
           switch(SelectedWord[i])
           {  
              
               case 'A' : if((WhichİsUsed==1&&Another==0)||(WhichİsUsed==2&&Another!=0)) {DrawLineEx(Avec,temp,20,(Color){0,0,0,100});
           if(temp.x!=Mvec.x&&temp.y!=Mvec.y){i++;CizgiCizLvl4(SelectedWord,Avec,Bvec,Cvec,Dvec,Mvec);}}
              else {
                DrawLineEx(Bvec,temp,20,(Color){0,0,0,100});
              if(temp.x!=Mvec.x&&temp.y!=Mvec.y){i++;CizgiCizLvl4(SelectedWord,Avec,Bvec,Cvec,Dvec,Mvec);}}
               break;
               case 'D' : DrawLineEx(Cvec,temp,20,(Color){0,0,0,100});
               if(temp.x!=Mvec.x&&temp.y!=Mvec.y){i++;CizgiCizLvl4(SelectedWord,Avec,Bvec,Cvec,Dvec,Mvec);}
               break;
               case 'M' : DrawLineEx(Dvec,temp,20,(Color){0,0,0,100});
               if(temp.x!=Mvec.x&&temp.y!=Mvec.y){i++;CizgiCizLvl4(SelectedWord,Avec,Bvec,Cvec,Dvec,Mvec);}
               break;
          }
          }
          else WhichİsUsed=0;
          i =0;
                  
                
       } 
