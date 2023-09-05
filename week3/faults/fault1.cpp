// C++ program to demonstrate segmentation
// fault when array out of bound is accessed.
#include <iostream>
using namespace std;

int main()
{
int arr[2];
arr[12] = 10; // Access out of bound
return 0;
}
