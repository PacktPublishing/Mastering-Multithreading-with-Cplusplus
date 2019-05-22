#include <cstdlib>
#include <unistd.h>

 int main() {
 char* arr = (char*) malloc(10);
 int* arr2 = (int*) malloc(sizeof(int));
 write(1, arr, 10 );
 exit(arr2[0]);
 }
