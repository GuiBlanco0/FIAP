#include <stdio.h>

// Void does't have to return any value
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int x = 10; int y = 20;
    swap(&x, &y);
    printf("X = %d\nY = %d", x, y);
    
    return 0;
}