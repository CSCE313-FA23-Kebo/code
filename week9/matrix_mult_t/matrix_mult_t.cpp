// Program to multiply two matrix using threads
#include <bits/stdc++.h>

#include <thread>
#include <iostream>
#include <vector>
#include <chrono>
#include <mutex>

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

using namespace std;

// maximum size of matrix
#define MAX 4

// maximum number of threads
#define MAX_THREAD 4

int matA[MAX][MAX];
int matB[MAX][MAX];
int matC[MAX][MAX];
int step_i = 0;

void* multi(void* arg)
{
	int i = step_i++; //i denotes row number of resultant matC

	for (int j = 0; j < MAX; j++) 
	for (int k = 0; k < MAX; k++) 
		matC[i][j] += matA[i][k] * matB[k][j]; // rows calculation

	return NULL;
}

// Driver Code
int main()
{
	double start, end;

	// Generating random values in matA and matB
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			matA[i][j] = rand() % 10;
			matB[i][j] = rand() % 10;
		}
	}

	// Displaying matA
	cout << endl
		<< "Matrix A" << endl;
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) 
			cout << matA[i][j] << " ";
		cout << endl;
	}

	// Displaying matB
	cout << endl
		<< "Matrix B" << endl;
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) 
			cout << matB[i][j] << " ";	 
		cout << endl;
	}

	// ##### START OF SECTION#####
    start = chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count();

	// declaring four threads
	pthread_t threads[MAX_THREAD];

	// Creating four threads, each evaluating its own part
	for (int i = 0; i < MAX_THREAD; i++) {
		int* p = nullptr; // Initialize p
		pthread_create(&threads[i], NULL, multi, (void*)(p));
	}

	// joining and waiting for all threads to complete
	for (int i = 0; i < MAX_THREAD; i++) 
		pthread_join(threads[i], NULL); 

	end = chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count();
	// ##### END OF SECTION #####

	printf("\nTime to complete: %f seconds\n", (end - start) * 1e-9);

	// Displaying the result matrix
	cout << endl
		<< "Multiplication of A and B" << endl;
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) 
			cout << matC[i][j] << " ";	 
		cout << endl;
	}
	return 0;
}
