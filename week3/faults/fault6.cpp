#include <iostream>
using namespace std;

int main() {
  int* ptr = new int;  // Allocate memory
  delete ptr;  // Free the allocated memory
  *ptr = 10;  // Use the memory after it has been freed
  return 0;
}
