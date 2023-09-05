#include <iostream> 
#include <new>

int main () { 
  try
  { 
     int * myarray = new int[1000000000000]; // This allocation exceeds the available memory size, such a large allocation is not possible.
  } 
  catch (std::bad_alloc & exception) 
  { 
     std::cerr << "bad_alloc detected: " << exception.what(); 
  } 
  return 0; 
} 