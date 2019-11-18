#include <stdio.h>
#include <stdlib.h>

int main (){
    int i=99, w=34, h=23;
    printf("if i=%d, w=%d, h=%d, then surface area=%d, and volume=%d", i, w, h, (i*w+i*h+w*h)*2, i*h*w);
    return 0;
}
