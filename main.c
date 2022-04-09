#include <stdio.h>
#include <stdlib.h>
#include<time.h>
void wpisz(int n,int *tab)
{
    srand(time(NULL));
  int i;
    for(i=0;i<n;i++)
    {
        tab[i]=0+rand()%21;
    }
}
void wypisz(int n, int *tab)
{
    int i;
   for(i=0;i<n;i++)
    {
    printf(" %d ",tab[i]);
    }


}

void sort_przez_proste_wstawienie(int n,int *tab)
{
   int i,j,t;
    for (i=1;i<n; ++i)
    {
        j=i;
        while((j>0)&&(tab[j-1]>tab[j]))
        {
            t=tab[j];
            tab[j]=tab[j-1];
            tab[j-1]=t;
            --j;
        }
    }
}
void sort_przez_wstawianie_polowkole(int n,int *tab)
{
    int i,j,x,first,last;
   for (j=n-2;j>=0;j--)
       {
        x=tab[j];
        first=j;
        last=n;

    while(last-first>1)
        {
            i=(first+last)/2;
            if (x<=tab[i])
            {
            last=i;
            }
            else
            {
            first=i;
            }
        }
        for(i=j;i<first;i++)
        {
        tab[i]=tab[i+1];
        }
        tab[first]=x;
        }
}
int main()
{

    int n,k;
    int *tab=NULL;
    int *tablica=NULL;
    printf("Podaj ilosc danych do zapisani w tablicy: ");
    scanf("%d",&n);
        puts(" ");
    tab=malloc(n*sizeof(int));
    tablica=malloc(n*sizeof(int));
    wpisz(n,tab);
    wpisz(n,tablica);

    wypisz(n,tab);
    printf("\n___________________________\n");
    puts("");
    wypisz(n,tablica);
    printf("\n___________________________\n");

    puts("");
   while(1)
   {
    printf("Wybierz dzialanie do wykonania :\n");
    printf("1: Sortowanie przez proste wstawianie\n");
    printf("2: Sortowanie przez wstawianie polowkowe\n");
    printf("3: Zakonczenie dzialania programu\n");
    scanf("%d",&k);
    switch(k)
    {
    case 1:
        sort_przez_proste_wstawienie(n,tab);
        wypisz(n,tab);
        puts("");
        free(tab);

    break;
    case 2:
        sort_przez_wstawianie_polowkole(n,tablica);
        wypisz(n,tablica);
        puts("");
        free(tablica);
        break;
    case 3:
        free(tab);
        free(tablica);
        tab=NULL;
        tablica=NULL;
    return 0;
    break;
    }

   }
    free(tab);
    free(tablica);
    tab=NULL;
    tablica=NULL;
    return 0;
}
