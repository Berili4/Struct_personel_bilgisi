#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//personel adlarina göre personel bilgilerinin alfabetik siralanmasi.
struct personel{

      int sifre;
      char adsoyad[20];
      int yas;
      float maas;
      char cinsiyet[10];

};
void sirala(struct personel *kisiler,int m)
{
   int i,j;
   struct personel t;//yer degistirmedeki gecici gibidir.
   for(i=0;i<m-1;i++)
   {
       for(j=i+1;j<m;j++)
       {
           if(strcmp(kisiler[i].adsoyad,kisiler[j].adsoyad)>0)//soldaki buyukse pozitif dondurur.
           {
               t=kisiler[i];
               kisiler[i]=kisiler[j];
               kisiler[j]=t;
           }
       }
   }
}
void listele(struct personel *kisiler,int m)
{
    for(int i=0;i<m;i++)
    {
        printf("sifre:%d adsoyad:%s yas:%d maas:%d cinsiyet:%s\n",kisiler[i].sifre,kisiler[i].adsoyad,kisiler[i].yas,kisiler[i].maas,kisiler[i].cinsiyet);
    }
}
int main()
{
    int m;
    printf("kac personel olacagini giriniz:");
    scanf("%d",&m);
    struct personel kisiler[m];

    for(int i=0;i<m;i++)
    {
        printf("sifre:");
        fflush(stdin);
        scanf("%d",&kisiler[i].sifre);

        printf(" ad soyad giriniz:");
        fflush(stdin);
        fgets(kisiler[i].adsoyad,m,stdin);

        printf("yas:");
        fflush(stdin);
        scanf("%d",&kisiler[i].yas);

        printf("cinsiyet giriniz:");
        fflush(stdin);
        fgets(kisiler[i].cinsiyet,m,stdin);

    }
    sirala(kisiler,m);
    listele(kisiler,m);


    return 0;
}
