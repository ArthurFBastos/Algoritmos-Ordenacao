#include <stdlib.h>
#include <stdio.h>
#include "RascunhoOrd.h"


void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}


void Bubble_sort(int *lista,int tam){
    int i,aux;
    for (int j = 0; j < tam; j++){
        for(i=0; i < tam - 1;i++){
            if (lista[i] > lista[i+1]){
                swap(&lista[i],&lista[i+1]);
            }
        }
    }
}


void exibir(int *lista,int tam){
    int i;
    for( i = 0; i < tam; i++ ){
        printf( "%s%d", (i>0)?", ":"", lista[i] );
    }
    printf("\n");
    puts("------------------------------------------");
}


void Selection_sort(int *lista,int tam){
    int i,j,min;
    for (i=0;i<tam;i++){
        min = i;
        for(j = i+1; j < tam;j++){
            if(lista[j]< lista[min]){
                min = j;
            }
            
        }   
        swap(&lista[i],&lista[min]);
    }
}

void Insertion_sort(int *lista,int tam){
    int i,j,aux;
    for (i = 1; i < tam; i++){
        aux = lista[i];
        for (j = i; (j > 0) && (aux < lista[j-1]);j--){
            lista[j] = lista[j-1];
        }
        lista[j] = aux;
    }
}

void Shell_sort(int *lista, int tam){

    int i , j , valor;
    int aux = 1;

    while(aux < tam) {
        aux = 3*aux+1;
    }
    while(aux > 1) {
        aux /= 3;
        for(i = aux; i < tam; i++){
            valor = lista[i];
            j = i - aux;

            while (j >= 0 && valor < lista[j]){
                lista[j + aux] = lista[j];
                j -= aux;
            }
            lista[j + aux] = valor;
        }
    }
}

void Quick_sort( int *lista, int start, int end){
    if( start < end ){
        int l = start + 1;
        int r = end;
        int p = lista[start];
        while( l < r ){
            if( lista[l] <= p ){
                l++;
            }
            else if( lista[r] >= p ){
                r--;
            }
            else{
                swap( &lista[l], &lista[r] );
            }
        }
        if( lista[l] < p ){
            swap( &lista[l], &lista[start] );
            l--;
        }
        else{
            l--;
            swap( &lista[l], &lista[start] );
        }
        Quick_sort( lista, start, l);
        Quick_sort( lista, r, end);
    }
}

void Merge_sort(int *lista, int start, int end) {
    int i, j, k, meio, *vet_temp;
    if(start == end) return;
    meio = (start + end ) / 2;

    Merge_sort(lista, start, meio);
    Merge_sort(lista, meio + 1, end);

    i = start;
    j = meio + 1;
    k = 0;
    vet_temp = (int *) malloc(sizeof(int) * (end - start + 1));

    while(i < meio + 1 || j  < end + 1) {
        if (i == meio + 1 ) { 
            vet_temp[k] = lista[j];
            j++;
            k++;
        }
        else {
            if (j == end + 1) {
                vet_temp[k] = lista[i];
                i++;
                k++;
            }
            else {
                if (lista[i] < lista[j]) {
                    vet_temp[k] = lista[i];
                    i++;
                    k++;
                }
                else {
                    vet_temp[k] = lista[j];
                    j++;
                    k++;
                }
            }
        }

    }
    for(i = start; i <= end; i++) {
        lista[i] = vet_temp[i - start];
    }
    free(vet_temp);
}