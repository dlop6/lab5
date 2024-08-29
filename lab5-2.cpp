#include <stdio.h>
#include <omp.h>

#define N 100000000  // Definimos N como una constante grande

int main() {
    int sum = 0;
    double start_time, end_time;

    // Comienza a medir el tiempo de ejecución
    start_time = omp_get_wtime();

    #pragma omp parallel for reduction(+:sum)
    for (int i = 1; i <= N; i++) {
        sum += i;
    }

    // Termina de medir el tiempo de ejecución
    end_time = omp_get_wtime();

    // Imprimir el resultado de la suma
    printf("Suma de los primeros %d numeros: %d\n", N, sum);

    // Imprimir el tiempo de ejecución
    printf("Tiempo de ejecucion: %f segundos\n", end_time - start_time);

    return 0;
}
