#include <stdio.h>

int main()
{
    FILE *dosya = fopen("LvlTut.txt","w");
    if(dosya!=NULL)
    {
        fprintf(dosya,"%d",00000);
    }
    else
    {
       printf("hata!");
    }
}