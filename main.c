#include <stdlib.h>
#include <stdio.h>
#include "RascunhoOrd.h"

int main(){
    int i,tam;
    printf("Tamanho do vetor ");
    scanf("%d",&tam);
    int lista[tam];
    for (i=0;i<tam;i++)
    {  
        printf("Elemento %d = ",i);
        scanf("%d",&lista[i]);
    }


    Bubble_sort(lista,tam);
    exibir(lista,tam);


    Selection_sort(lista,tam);
    exibir(lista,tam);


    Insertion_sort(lista,tam);
    exibir(lista,tam);


    Shell_sort(lista,tam);
    exibir(lista,tam);


    Quick_sort(lista,0,tam-1);
    exibir(lista,tam);


    Merge_sort(lista,0,tam-1);
    exibir(lista,tam);
    
    return 0;
}