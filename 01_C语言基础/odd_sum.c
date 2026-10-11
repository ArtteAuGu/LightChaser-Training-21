#include <stdio.h>

int odd_sum(int num, int sum){
    if(num % 2 == 0) num--;
    sum += num;
    if(num > 1) return odd_sum(num - 2, sum);
    return sum;
}

int main()
{
    printf("%d", odd_sum(100, 0));
}
