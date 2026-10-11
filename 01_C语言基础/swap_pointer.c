#include <stdio.h>

void Exchange(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int a, b;
    printf("Press two numbers to exchange the value:");
    scanf("%d %d", &a, &b);
    Exchange(&a, &b);
    printf("Result: a = %d, b = %d", a, b);
}
