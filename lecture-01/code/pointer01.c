#include <stdio.h>

char arr1 [] = {'A','B','C','D','E'};
int arr2[] = {1,2,3,4,5};

int main() {
  char *p1 = &arr1[2];
  printf("%c\n", *(p1 + 2));
  
  void *p2 = &arr2[1];
  int i2 = *((int *)p2 + 1);
  printf("%d\n", i2);

  int* p = (int*)p2;
  for(int i = 0; i < 4; ++i) {
    int i3 = *(p + i);
    printf("*(p+%d) = %d\n", i, i3);	  
  }	  
}	
