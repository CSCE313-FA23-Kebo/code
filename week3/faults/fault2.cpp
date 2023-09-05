#include <iostream>
using namespace std;

int main() {
  cout << "Activity grades" << endl;
  int* grades; // Uninitialized Pointer
  grades[5] = 10;  
}

/*
int main() {
  cout << "Activity grades" << endl;
  
  // Allocate memory for a single integer
  int* grades = new int;
  *grades = 10;
  delete grades;  // Free the allocated memory

  return 0;
}
*/