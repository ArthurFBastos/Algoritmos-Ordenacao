#include <stdlib.h>
#include <stdio.h>
#include "RascunhoOrd.h"
#include <time.h>

void randomArray(int lista[], int tam){
    int numero;
    for (int i = 0; i < tam; i++){
        numero = (rand() % 100);
        lista[i] = numero;
    }
}

int main(){
    
    int tam;
    scanf("%d", &tam);

    int lista[tam];
    randomArray(lista,tam);


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