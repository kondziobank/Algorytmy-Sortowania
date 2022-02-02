#include<stdio.h>
#include<time.h>
#include<stdlib.h>

void swap(int* a, int* b){

    int c;
    c = (*b);
    (*b) = (*a);
    (*a) = c;
}

int main()
{   

    int ilosc_el,index,p,k,i,j,x,q;                         
    int wartosc, qwerty=250000, trewq=0, losowa=rand();                            
    printf("Ile liczb ma miec tablica: ");
    scanf("%d",&ilosc_el);
    int tablica[ilosc_el];
    printf("\n");

    printf("Wybierz 1, jezeli dane maja byc losowe\n");
    printf("Wybierz 2, jezeli dane maja miec porzadek rosnacy\n");
    printf("Wybierz 3, jezeli dane maja miec porzadek malejacy\n");
    printf("Wybierz 4, jezeli dane maja byc stale\n");
    printf("Wybierz 5, jezeli dane maja byc A-ksztaltne\n");
    printf("Podaj wariant wejscia: ");
    scanf("%d", &wartosc);

    if (wartosc == 1){
        for(index=0; index < ilosc_el; index++){
            tablica[index] = rand();
        }
    }
    else if (wartosc == 2){
        for(index=0; index < ilosc_el; index++){
            tablica[index]=trewq;
            trewq++;
        }
    }
    else if (wartosc == 3){
        for(index=0; index < ilosc_el; index++){
            tablica[index]=qwerty;
            qwerty--;
        }
    }
    else if (wartosc == 4){
        for(index=0; index < ilosc_el; index++){
            tablica[index]= losowa;
        }
    }
    else if (wartosc == 5){
        for (index=0; index < ilosc_el/2; index++){
            tablica[index]= trewq;
            trewq++;
        }
    
        for (index=ilosc_el/2; index < ilosc_el; index++){
            tablica[index]=trewq-1;
            trewq--;
        }
    }
    else{
        printf("Podaj prawidlowa wartosc: ");
        scanf("%d", &wartosc);
    }
    

    printf("Tablica do posortowania: ");
    for (k=0; k < index; k++){
        printf("%d ",tablica[k]);
    }  
    printf("\n\n");

    srand(time(NULL));
    clock_t start = clock();

    for(i = 2; i <= ilosc_el; i++){
      j = i; 
      p = j / 2;
      x = tablica[i];
        while((p > 0) && (tablica[p] < x)){
          tablica[j] = tablica[p];
          j = p; 
          p = j / 2;
          }
      tablica[j] = x;
  }

    for(i = ilosc_el; i > 1; i--){
    swap(&tablica[1], &tablica[i]);
    j = 1; 
    p = 2;
    while(p < i){
        if((p + 1 < i) && (tablica[p + 1] > tablica[p]))
          q = p + 1;
        else
          q = p;
        if(tablica[q] <= tablica[j]) 
        break;
      swap(&tablica[j], &tablica[q]);
      j = q; 
      p = 2 * j;
      }
  }

    printf("\n");
    printf("Ciag posortowany: ");
    for (i=1; i<=ilosc_el; i++){
        printf("%d ", tablica[i]);
    }
    printf("\n\n");
    printf("Czas wykonywania: %lu ms\n", clock() - start);
    
    return 0;
}