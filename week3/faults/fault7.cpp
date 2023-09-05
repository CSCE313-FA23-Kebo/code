#include <iostream>
using namespace std;

int main() {
  int* ptr = new int;  // Allocate memory
  delete ptr;  // Free the memory
  delete ptr;  // Attempt to free the memory again
  return 0;
}