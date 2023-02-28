#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>

// tic tac toe oyunu


char matris[3][3] = {'1','2','3','4','5','6','7','8','9'};
matrisyazdir()
{
    int i,j;
    for(i=0;i<3;i++)
    {
        printf("\n\t");
        for(j=0;j<3;j++)
        {
            printf("%c\t ",matris[i][j]);
        }
        printf("\n\n");
    }
}
 
void xGiris(int sayi)
{
    char *ptr=matris;  // matrisin adresini tutan pointer olusturdum
    *(ptr+sayi-1)='X'; // pointerin tuttugu adresin degerini degistirdim

}

int sayiUret()
{
    int sayi;
    sayi=rand()%9+1;
    int sonuc=0;
    char *ptr=matris;
    while(sonuc!=1)
    {
        if( * (ptr+sayi-1)== 88 || * (ptr+sayi-1)== 79) // 88 ve 79 ascii degerleri 88'de x var mi 79'da o var mi diye kontrol ediyoruz
        {
            sayi++;
            if(sayi==10) 
            sayi=1;
        }
        else
        sonuc=1;

        }
        
    
    return sayi;
}

void oGiris(int sayi)
{
    char *ptr=matris;  // matrisin adresini tutan pointer olusturdum
    *(ptr+sayi-1)='O'; // pointerin tuttugu adresin degerini degistirdim

}

int xkontrol()
{

    char *ptr=matris;
    if(*(ptr+0)==88 && *(ptr+1)==88 && *(ptr+2)==88)  // ptr+0 ilk degerine esit olarak kabul edelim.
    return 1;
    else if(*(ptr+3)==88 && *(ptr+4)==88 && *(ptr+5)==88)  //satir kontrol
    return 1;
    else if(*(ptr+6)==88 && *(ptr+7)==88 && *(ptr+8)==88) // sekiz demek 9. deger demek 0 dan basladıgı için
    return 1; 

    else if(*(ptr+0)==88 && *(ptr+3)==88 && *(ptr+6)==88) // sutun kontrol
    return 1;  
    else if(*(ptr+1)==88 && *(ptr+4)==88 && *(ptr+7)==88)
    return 1;
    else if(*(ptr+2)==88 && *(ptr+5)==88 && *(ptr+8)==88)
    return 1;

    else if(*(ptr+0)==88 && *(ptr+4)==88 && *(ptr+8)==88)   // capraz kontrol
    return 1;
    else if(*(ptr+6)==88 && *(ptr+4)==88 && *(ptr+2)==88)
    return 1;
    else 
    return 0;

 }
    int okontrol()
    {
        char *ptr=matris;
    if(*(ptr+0)==79 && *(ptr+1)==79 && *(ptr+2)==79)  // ptr+0 ilk degerine esit olarak kabul edelim.
    return 2;
    else if(*(ptr+3)==79 && *(ptr+4)==79 && *(ptr+5)==79)  //satir kontrol
    return 2;
    else if(*(ptr+6)==79 && *(ptr+7)==79 && *(ptr+8)==79) // sekiz demek 9. deger demek 0 dan basladıgı için
    return 2; 

    else if(*(ptr+0)==79 && *(ptr+3)==79 && *(ptr+6)==79) // sutun kontrol
    return 2;  
    else if(*(ptr+1)==79 && *(ptr+4)==79 && *(ptr+7)==79)
    return 2;
    else if(*(ptr+2)==79 && *(ptr+5)==79 && *(ptr+8)==79)
    return 2;

    else if(*(ptr+0)==79 && *(ptr+4)==79 && *(ptr+8)==79)   // capraz kontrol
    return 2;
    else if(*(ptr+6)==79 && *(ptr+4)==79 && *(ptr+2)==79)
    return 2;
    else
    return 0;
    }



int main ()
{

  srand(time(0));
  matrisyazdir();
  int sayi;
  int sonuc=0;
  int adet=1;

  while(sonuc!= 5)
  {
    adet++;
    printf("x isaretinin konulacagi kutu: ");
    scanf("%d",&sayi);
    xGiris(sayi);
    matrisyazdir();
    sonuc=xkontrol();
    if(sonuc==1)
    {
        printf("x kazandi");
        break;
    }
     
    system("color 0a");
    printf("o isaretinin konulacagi kutu: ");
    sayi=sayiUret();
    printf("sayi: %d,sayi");
    oGiris(sayi);
    matrisyazdir();
    sonuc=okontrol();
    if(sonuc==2)
    {
        printf(" bilgisayar o kazandi");
        break;
    }
    if (adet==5)
    {
        printf("berabere");
        break;
    }

  }


    return 0;
}