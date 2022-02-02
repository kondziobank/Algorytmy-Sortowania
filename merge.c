#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 

void merge(int i, int j, int tablica[], int tabhelp[]) {
	if (j <= i) {
        return; 
    }
    int middle = (i + j) / 2;

    merge(i, middle, tablica, tabhelp);     
    merge(middle + 1, j, tablica, tabhelp);    

    int left = i, right = middle + 1, z;    

    for (z = i; z <= j; z++) {
        if (left == middle + 1) {      
            tabhelp[z] = tablica[right];
            right++;
        } else if (right == j + 1) {        
            tabhelp[z] = tablica[left];
            left++;
        } else if (tablica[left] < tablica[right]) {        
            tabhelp[z] = tablica[left];
            left++;
        } else {        
            tabhelp[z] = tablica[right];
            right++;
        }
    }
    for (z = i; z <= j; z++) {     
        tablica[z] = tabhelp[z];
    }
}

int main() {

  int ilosc_el,index,k,j,i; 
  int wartosc, qwerty=250000, trewq=0, losowa=rand();   

    printf("Ile liczb ma miec tablica: ");
    scanf("%d",&ilosc_el);
    int tablica[ilosc_el], tabhelp[ilosc_el];
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

    srand(time(NULL));
    clock_t start = clock();

    merge(0, ilosc_el-1, tablica, tabhelp);
 
  printf("\n");
    printf("Ciag posortowany: ");
    for (i=0; i<ilosc_el; i++){
        printf("%d ", tablica[i]);
    }
    printf("\n\n");
    printf("Czas wykonywania: %lu ms\n", clock() - start);
 
  return 0;
}