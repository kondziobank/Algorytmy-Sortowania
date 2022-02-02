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

    int ilosc_el,index,k;                            
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

    for (int i=0; i < ilosc_el-1; i++){
        for (int j=0; j < ilosc_el-1-i; j++){
            if (tablica[j] > tablica[j+1])
                 swap(&tablica[j], &tablica[j+1]);    
            
        }
    }

    printf("\n");
    printf("Ciag posortowany: ");
    for (int i=0; i<ilosc_el; i++){
        printf("%d ", tablica[i]);
    }
    printf("\n\n");
    printf("Czas wykonywania: %lu ms\n", clock() - start);

    return 0;
}