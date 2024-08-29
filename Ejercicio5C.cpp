#include <iostream>
#include <omp.h>
#include <vector>

using namespace std;

// Definir tamaños de los vectores
#define DBIN_SIZE 1024
#define KEYS_SIZE 10
#define MAX_POSITIONS DBIN_SIZE  // Asumir un tamaño máximo para DBout

// Función para buscar claves en DBin
void producer(const vector<int>& DBin, const vector<int>& keys, vector<int>& DBout, int& count) {
    #pragma omp parallel for
    for (int i = 0; i < DBIN_SIZE; i++) {
        for (int j = 0; j < KEYS_SIZE; j++) {
            if (DBin[i] == keys[j]) {
                #pragma omp critical
                {
                    if (count < MAX_POSITIONS) {
                        DBout[count++] = i;
                    }
                }
            }
        }
    }
}

// Función principal
int main() {
    // Inicializar DBin y keys con valores de ejemplo
    vector<int> DBin(DBIN_SIZE);
    vector<int> keys(KEYS_SIZE);
    vector<int> DBout(MAX_POSITIONS);
    int count = 0;  // Contador para las posiciones encontradas

    // Llenar DBin y keys con valores de ejemplo
    for (int i = 0; i < DBIN_SIZE; i++) {
        DBin[i] = i % 100;  // Valores de ejemplo en DBin
    }

    for (int j = 0; j < KEYS_SIZE; j++) {
        keys[j] = j * 10;  // Valores de ejemplo en keys
    }

    // Ejecutar la tarea del productor
    producer(DBin, keys, DBout, count);

    // Imprimir los primeros valores de DBout para verificar la funcionalidad
    cout << "Posiciones en DBout: ";
    for (int i = 0; i < count; i++) {
        cout << DBout[i] << " ";
    }
    cout << endl;

    return 0;
}
