#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef struct point* p_point;
struct point {
  int x;
  int y;  
};


int main() {	

p_point p;
p = (p_point) malloc(2 * sizeof(struct point));
p->x = 0;
p->y = 0;

(p+1)->x = 3;
(p+1)->y = 5;

printf("p->x: %d ", p->x);
printf("p->y: %d\n", p->y);

printf("(p+1)->x: %d ", (p+1)->x);
printf("(p+1)->y: %d\n", (p+1)->y);
}	
