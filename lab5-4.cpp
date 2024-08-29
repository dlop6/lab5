#include <stdio.h>
#include <omp.h>
#include <iostream>

int main(){

    int N = 10;
    int a = 0;
    int b = 0;

    #pragma imp parallel for shared(a) private(b)

    for (int i = 0; i < N; i++){
       a = i*2;

       #pragma omp critical
       {
           b += a;
       }

       printf("Hilo %d: a = %d, b = %d\n", omp_get_thread_num(), a, b);
    
    }

    printf("a = %d\n", a);
    printf("b = %d\n", b);

    return 0;


}