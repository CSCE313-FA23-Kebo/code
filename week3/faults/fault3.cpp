#include <iostream>
using namespace std;

int main() {
  int* number; // Uninitialized Pointer
  *number = 57;
  *(number + 2) = 6; // Incorrect Pointer Arithmetic
}
