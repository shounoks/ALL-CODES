
#include <stdio.h>

int myFunction() {
  // Local variable that belongs to myFunction
  int x;
  scanf("%d",&x);

  // Print the variable x
  printf("%d", x);
}

int main() {
  myFunction();
  return 0;
}
