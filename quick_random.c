#include<stdio.h>
#include<time.h>
#include<stdlib.h>
 
int pivot(int tablica[],int parametr,int ilosc_el)
{
	int v,i,j,zmienna;
	v=tablica[parametr];
	i=parametr;
	j=ilosc_el+1;
	
	do{
			do
				i++;
			
			while(tablica[i]<v && i<=ilosc_el);
		

			do
				j--;
			while(v < tablica[j]);
		

			if(i<j){
				zmienna= tablica[i];
				tablica[i]= tablica[j];
				tablica[j]= zmienna;
			}

	}while(i<j);
	
	tablica[parametr]=tablica[j];
	tablica[j]=v;
	
	return(j);
}

void quick(int tablica[],int parametr,int ilosc_el)
{
	int j;
	if(parametr < ilosc_el){
		j= pivot(tablica, parametr, ilosc_el);
		quick(tablica, parametr, j-1);
		quick(tablica, j+1, ilosc_el);
	}
}

void swap(int* a, int* b){

    int c;
    c = (*b);
    (*b) = (*a);
    (*a) = c;
}

int main()
{   

    int ilosc_el,index,k,i,j;                          
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

    int random=rand()%ilosc_el;
    quick(tablica, random, ilosc_el);

    printf("\n");
    printf("Ciag posortowany: ");
    for (i=1; i<=ilosc_el; i++){
        printf("%d ", tablica[i]);
    }
    printf("\n\n");
    printf("Czas wykonywania: %lu ms\n", clock() - start);
    
    return 0;
}