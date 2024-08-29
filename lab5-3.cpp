#include <stdio.h>
#include <omp.h>
#include <iostream>

#define N 20 // size of fibonacci sequence
#define ARRAY_SIZE 10 //arreglo del qu ese buscara el maximo

void factorial(int n){
    int fact = 1;
    for(int i = 1; i <= n; i++){
        fact *= i;
    }
    
    printf("Factorial de %d: %d\n", n, fact);
}

void fibonacci(int n){
    int fibo[n];
    fibo[0] = 0;
    fibo[1] = 1;
    for(int i = 2; i < n; i++){
        fibo[i] = fibo[i-1] + fibo[i-2];
    }
    
    printf("Serie de fibonacci hasta %d: ", n);
    for(int i = 0; i < n; i++){
        printf("%d ", fibo[i]);
    }
}

void max(int arr[], int n){
    int max = arr[0];
    for(int i = 1; i < n; i++){
        if(arr[i] > max){
            max = arr[i];
        }
    }
    
    printf("Maximo del arreglo: %d\n", max);
}

int main() {
    int arr[ARRAY_SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    double start_time, end_time;
    start_time = omp_get_wtime();
    
    #pragma omp parallel sections
    {
        #pragma omp section
        {
            factorial(20);
        }
        
        #pragma omp section
        {
            fibonacci(N);
        }
        
        #pragma omp section
        {
            max(arr, ARRAY_SIZE);
        }
    }

    end_time = omp_get_wtime();

    printf("Tiempo de ejecucion: %f segundos\n", end_time - start_time);
    
    return 0;
}