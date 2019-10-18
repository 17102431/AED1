#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int vet[], int tam){
    int aux, i, j;
    for (i = 0; i < tam - 1; i++){
        for (j = 0; j <tam - i - 1 ; j++){
            if (vet[j]>vet[j+1]){            
                aux      = vet[j];
                vet[j]   = vet[j+1];
                vet[j+1] = aux; 
            }
        }
    }
    
}

void insertionSort(int vet[], int tam){
    int aux, i, j;
    for (j = 1; j < tam; j++){
        i = j - 1;
        aux = vet[j];
        while ((i >= 0) && (aux <vet[i])){
            vet[i+1] = vet[i];
            i--;
        }
        vet[i+1] = aux;
    }
}

void selectionSort(int vet[], int tam){
    int min,tmp,i,j,min_id;
    
    for (i=0; i < tam -1; i++) {
        min = vet[i];
        for (j=i+1; j < tam; j++){
            if (vet[j] < min) {
                min = vet[j];
                min_id = j;
            }
            tmp = vet[i];
            vet[i] = vet[min_id];
            vet[min_id] = tmp;
        }
        min_id = i+1;
    }
}

void Quicksort (int data[],int left,int right) {
    int mid,tmp,i,j;
    i = left;
    j = right;
    mid = data[(left + right)/2];
    do {
        while(data[i] < mid)
            i++;
        while(mid < data[j])
            j--;
        if (i <= j) {
            tmp = data[i];
            data[i] = data[j];
            data[j] = tmp;
            i++;
            j--;
        }
    }while (i <= j);
    if (left < j)
        Quicksort(data,left,j);
    if (i < right)
        Quicksort(data,i,right);
}

int main(){
    int vet[10];
    int vetAux[10];
    int opc;    
    for (int i = 0; i < 10; i++){ 
        scanf("%d",&vet[i]);
    }
    for (int i = 0; i < 10; i++){
        vetAux[i] = vet[i];
    }
    
    while(1){
        printf("\n################\nordenar vetor com:\n1.bubble\n2.insertion\n3.selection\n4.quick\n5.sair\n\n");
        scanf("%d",&opc);
        if(opc == 1){
            printf("################\nVetor NAO ordenado\n");
            for (int i = 0; i < 10; i++){
                printf("vet[%d]=%d\n", i, vet[i]);
            }
            bubbleSort(vet,10);
            printf("\n##### VETOR ORDENADO com bubbleSort #####\n\n");
            for (int i = 0; i < 10; i++){
                printf("vet[%d]=%d\n", i, vet[i]);
            }       
        }
        if(opc == 2){
            printf("################\nVetor NAO ordenado\n");
            for (int i = 0; i < 10; i++){
            printf("vet[%d]=%d\n", i, vet[i]);
            }
            insertionSort(vet,10);
            printf("\n##### VETOR ORDENADO com insertion #####\n\n");
            for (int i = 0; i < 10; i++){
                printf("vet[%d]=%d\n", i, vet[i]);
            }       
        }
        if(opc == 3){
            printf("################\nVetor NAO ordenado\n");
            for (int i = 0; i < 10; i++){
                printf("vet[%d]=%d\n", i, vet[i]);
            }
            selectionSort(vet,10);
            printf("\n##### VETOR ORDENADO com selection #####\n\n");
            for (int i = 0; i < 10; i++){
                printf("vet[%d]=%d\n", i, vet[i]);
            }       
        }
        if(opc == 4){
            printf("################\nVetor NAO ordenado\n");
            for (int i = 0; i < 10; i++){
                printf("vet[%d]=%d\n", i, vet[i]);
            }
            Quicksort(vet, 0, 9);
            printf("\n##### VETOR ORDENADO com quick #####\n\n");
            for (int i = 0; i < 10; i++){
                printf("vet[%d]=%d\n", i, vet[i]);
            }       
        }
        if(opc == 5){
            exit(1);       
        }
        for (int i = 0; i < 10; i++){
            vet[i] = vetAux[i];
        }
    }
}