// Program to multiply two matrix without threads

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

using namespace std;

// Maximum size of matrix
#define MAX 4

int matA[MAX][MAX]; // Matrice 1
int matB[MAX][MAX]; // Matrice 2
int matC[MAX][MAX]; // Destination matrice

// Function to multiply two matrices
void multiplyMatrices() {
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            matC[i][j] = 0;
            for (int k = 0; k < MAX; k++) { // MAC
                matC[i][j] += matA[i][k] * matB[k][j];
            }
        }
    }
}

int main() {
    double start, end;

    // Generating random values in matA and matB
    srand(time(0));
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            matA[i][j] = rand() % 10;
            matB[i][j] = rand() % 10;
        }
    }

    // Displaying matA
    cout << "Matrix A" << endl;
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++)
            cout << matA[i][j] << " ";
        cout << endl;
    }

    // Displaying matB
    cout << "\nMatrix B" << endl;
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++)
            cout << matB[i][j] << " ";
        cout << endl;
    }
    // ##### START OF SECTION#####
    start = chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count();

    // Multiply matrices A and B
    multiplyMatrices();

    end = chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count();
	// ##### END OF SECTION #####

    printf("\nTime to complete: %f seconds\n", (end - start) * 1e-9);

    // Displaying the result matrix
    cout << "Multiplication of A and B" << endl;
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++)
            cout << matC[i][j] << " ";
        cout << endl;
    }

    return 0;
}
