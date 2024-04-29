#include <stdio.h>

int GetDataToFile()
{
   FILE *dosya1 = fopen("LvlTut.txt","r");
   if(dosya1!=NULL)
   {int a=0;
   fscanf(dosya1,"%d",&a);
  fclose(dosya1);
   return a;}else return 0;
}

void ReWriteFile(int sayi)
{
    FILE *dosya2 = fopen("gecici.txt","w");
    if(dosya2!=NULL){
    fprintf(dosya2,"%d",sayi);}
    fclose(dosya2);
}
void IncreaseFileA(int num)
{   
   int sayi = GetDataToFile();
   sayi+=num;
   ReWriteFile(sayi);
  int bombos = remove("LvlTut.txt");
 int bos = rename("gecici.txt","LvlTut.txt");
}